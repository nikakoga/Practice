#include "Dealer.h"

Dealer::Dealer(Deck& _deck, HumanPlayer& _human, ComputerPlayer& _computer)
	: Player(_deck), human(_human), computer(_computer)
{
	name = "dealer";
	credits = 0;
}

void Dealer::ShowTable()
{
	std::cout << "Table contains:" << "\n";
	for (Card card : hand)
	{
		card.ShowCard();
	}
	std::cout << "\n";
}

bool Dealer::CreditCheck()
{
	if (creditsFromHuman == cresitsFromComputer)
	{
		return true;
	}
	return false;
}




