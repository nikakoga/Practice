#include "Dealer.h"

Dealer::Dealer(Deck& _deck, HumanPlayer& _human, ComputerPlayer& _computer)
	: Player(_deck), human(_human), computer(_computer)
{
	name = "dealer";
	credits = 0;
}

void Dealer::TakeCard()
{
	//0. sprawdza czy oboje gracze wylozyli na stol tyle samo
	while (!CreditCheck())
	{
		int toPay = HowManyNotEven();
		if (currentPlayer = Human) //!!!!!!! tu powinno byc ==
		{
			if (human.ChooseToMatchOrFold(toPay))
			{
				//pobieranie kasy
			}
			else
			{
				Pass();
			}
		}
		else
		{
			//funkcja decydujaca czy dolozyc czy spasowac u komputera
		}
	}
	//1. doklada karte
	hand.push_back(deck.GetCard());
	//2. wyswietla stol
	ShowTable();
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

void Dealer::SetWinner()
{
	//porownuje ktora reka jest silniejsza
}

bool Dealer::CreditCheck()
{
	if (creditsFromHuman == creditsFromComputer)
	{
		return true;
	}
	return false;
}

int Dealer::HowManyNotEven()
{
	int notEven = 0;
	if (creditsFromHuman > creditsFromComputer)
	{
		notEven = creditsFromHuman - creditsFromComputer;
	}
	else
	{
		notEven = creditsFromComputer - creditsFromHuman;
	}
	return notEven;
}

void Dealer::Pass()
{
	if (currentPlayer == 1)
	{
		//kasa do kompa
		computer.credits += credits;

	}
	else
	{
		//kasa do czlowieka
		human.credits += credits;
	}
}




