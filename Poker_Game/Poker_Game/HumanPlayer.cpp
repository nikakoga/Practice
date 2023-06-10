#include "HumanPlayer.h"

bool HumanPlayer::IsMatched()
{
	std::cout << "Do you want to:" << "\n" << "1 - match the current bet" << "\n" << "or" << "\n" << "2 - fold your hand";
	int respond = SafeRespond();
	if (respond == 1)
	{
		//dobijanie do stawki
		return true;
	}
	else
	{
		//passowanie
		return false;
	}
}

void HumanPlayer::TakeCard()
{
	hand.push_back(deck.GetCard());
	ShowHand();
}

void HumanPlayer::ShowHand()
{
	std::cout << "Your hand contains:" << "\n";
	for (Card card : hand)
	{
		card.ShowCard();
	}
}

int HumanPlayer::SafeRespond()
{
	int answer = 0;

	while (true) {
		std::cin >> answer;
		if (!std::cin || (answer != 1 && answer != 2)) {
			std::cout << "Wrong choice. Enter again: " << "\n";
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
