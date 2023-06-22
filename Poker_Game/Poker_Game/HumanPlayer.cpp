#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(Deck& deck) : Player(deck)
{
	std::string player;
	//std::cout << "Enter player name"<<"\n";
	//std::cin >> player;
	//name = player;
	name = "Nika";
	creditsOnTable = 0;
	credits = 1000;
	finished = false;
	bankrupt = false;
}

bool HumanPlayer::ChooseToMatchOrFold(int amount)
{
	std::cout << "Do you want to:" << "\n" << "1 - match the current bet" << "\n" << "or" << "\n" << "2 - fold your hand"<<"\n";
	int respond = SafeChooseBetweenTwo();
	if (respond == 1)
	{
		PayUp(amount, "match");
		return true;
	}
	else
	{
		//Pass();
		return false;
	}
}

bool HumanPlayer::ChooseRaise()
{
	std::cout << "Do you want to Raise? :" << "\n" << "1 - No" <<"\n" << "2 - Yes" << "\n";
	int respond = SafeChooseBetweenTwo();
	if (respond == 1)
	{
		finished = true; //ustawiam flage ze ten gracz juz chce skonczyc ture
		return false;
	}
	else
	{	
		return true;
	}
}

void HumanPlayer::Raise()
{
	bool validInput = false;
	while (!validInput)
	{
		std::cout << "How much?" << "\n";
		std::string input;
		std::cin >> input;

		if (IsInteger(input))
		{
			int number = std::stoi(input);
			if (number > 0)
			{
				PayUp(number, "raise");
				finished = false; //ustawiam flage ze ten gracz przedluza czas trwania tury
			}
			validInput = true;
		}
		else {
			std::cout << "Invalid input. Please try again or enter 0 if you dont want to raise." << "\n";
		}
	}
}

void HumanPlayer::TakeCard()
{
	hand.push_back(deck.GetCard());
	ShowHand();
}

void HumanPlayer::PayUp(int amount, std::string context)
{
	if (credits == 0)
	{
		bankrupt = true;
	}
	else if (credits >= amount)
	{
		credits -= amount;
		creditsOnTable += amount;
		std::cout << name<<" paid " << amount << " to " << context << "\n";
		std::cout << name<<" credits left: " << credits << "\n" << "\n";
	}
	else
	{
		std::cout << "This is more than " << credits << " you have" << "\n";

		if (context == "match" || context =="start")
		{
			//przegrana
			bankrupt = true;
		}
		else if (context == "raise")
		{
			 std::cout<< "Please try again or enter 0 if you dont want to raise" << "\n";
			 Raise();
		}
	}
}

void HumanPlayer::ShowHand()
{
	std::cout << "Your hand contains:" << "\n";
	for (Card card : hand)
	{
		card.ShowCard();
	}
}

void HumanPlayer::ShowCreditsInfo()
{
	std::cout << "Credits you spend: " << creditsOnTable << "\n";
}


int HumanPlayer::SafeChooseBetweenTwo()
{
	int answer = 0;

	while (true) {
		std::cin >> answer;
		if (!std::cin || (answer != 1 && answer != 2)) {
			std::cout << "There is no such option. Enter again: " << "\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			break;
		}
	}

	return answer;
}

bool HumanPlayer::IsInteger(std::string input)
{
	try {
		std::stoi(input);
		return true;
	}
	catch (const std::exception&) {
		
	}
	return false;
}
