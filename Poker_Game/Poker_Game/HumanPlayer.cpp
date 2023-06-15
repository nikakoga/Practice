#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(Deck& deck) : Player(deck)
{
	std::string player;
	std::cout << "Enter player name"<<"\n";
	std::cin >> player;
	name = player;
	creditsSpent = 0;
}

bool HumanPlayer::ChooseToMatchOrFold(int amount)
{
	std::cout << "Do you want to:" << "\n" << "1 - match the current bet" << "\n" << "or" << "\n" << "2 - fold your hand";
	int respond = SafeChooseBetweenTwo();
	if (respond == 1)
	{
		PayUp(amount,"match");
		return true;
	}
	else
	{
		//passowanie
		return false;
	}
}

bool HumanPlayer::ChooseRaise()
{
	std::cout << "Do you want to Raise? :" << "\n" << "1 - No" <<"\n" << "2 - Yes";
	int respond = SafeChooseBetweenTwo();
	if (respond == 1)
	{
		return false;
	}
	else
	{	
		return true;
	}
}

void HumanPlayer::Raise()
{
	std::cout << "How much?" << "\n";
	std::string input;
	std::cin >> input;

	if (IsInteger(input)) 
	{
		int number = std::stoi(input);
		PayUp(number, "raise");

	}
	else {
		std::cout << "Invalid input. Please enter an integer." << std::endl;
	}
}

void HumanPlayer::TakeCard()
{
	hand.push_back(deck.GetCard());
	ShowHand();
}

void HumanPlayer::PayUp(int amount, std::string context)
{
	if (credits >= amount)
	{
		credits -= amount;
		creditsSpent += amount;
		std::cout << "Your credits left: " << credits << "\n\n";
	}
	else
	{
		std::cout << "This is more than " << credits << " you have" << "\n";

		if (context == "match" || context =="start")
		{
			//przegrana
			lost = true;
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
