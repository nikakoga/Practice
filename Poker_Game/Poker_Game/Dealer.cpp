#include "Dealer.h"

Dealer::Dealer(Deck& _deck, HumanPlayer& _human, ComputerPlayer& _computer) 
	: Player(_deck), human(_human), computer(_computer)
{
	name = "dealer";
	credits = 0;
}

void Dealer::GiveCard()
{
	//0. sprawdza czy oboje gracze wylozyli na stol tyle samo
	while (!CreditCheck())
	{
		int toPay = HowManyNotEven();
		if (currentPlayer == Human) 
		{
			if (human.ChooseToMatchOrFold(toPay))
			{
				//pobieranie kasy
				human.PayUp(toPay);
			}
			else
			{
				Pass();
				break;
			}
		}
		else
		{
			//funkcja decydujaca czy dolozyc czy spasowac u komputera
			if (computer.ChooseToMatchOrFold(toPay))
			{
				//pobieranie kasy
				computer.PayUp(toPay);
			}
			else
			{
				Pass();
				break;
			}
			
		}
	}
	//1. doklada karte
	TakeCard();
	//2. wyswietla stol
	ShowTable();
}

//TO POWINNO BYC W KLASIE TURY
//computer.PayUp(startPay);
//human.PayUp(startPay);

void Dealer::SetTable()
{
	TakeCard();
	TakeCard();
	TakeCard();
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
	//potrzeba stworzyc kombinacje z wszystkich kart
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
	if (currentPlayer == Human)
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




