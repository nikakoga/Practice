#include "Dealer.h"

Dealer::Dealer(Deck& _deck, HumanPlayer& _human, ComputerPlayer& _computer) 
	: Player(_deck), human(_human), computer(_computer)
{
	name = "dealer";
	credits = 0;
}

void Dealer::CheckAmount()
{
	bool pass = false;

	//sprawdza czy aktualny gracz wylozyl odpowiednio duzo
	while (currentPlayer->creditsSpent < otherPlayer->creditsSpent)
	{
		int toPay = HowManyNotEven();
		//jesli nie to wybiera czy doplacic
		if (currentPlayer->ChooseToMatchOrFold(toPay))
		{
			currentPlayer->PayUp(toPay, "match");			
		}
		//czy spasowac
		else
		{
			pass = true;
			Pass();
			break;
		}

	}
	//jesli nie spasowal moze przebic
	if (!pass)
	{
		if (currentPlayer->ChooseRaise())
		{
			currentPlayer->Raise();
		}
	}
	
}

void Dealer::GiveCard()
{
	//gdzie indziej
	/*CheckAmount();
	NextPlayer();
	CheckAmount();*/
	
	//1. doklada karte
	TakeCard();
	//2. wyswietla stol
	ShowTable();

	if (hand.size() == 5)
	{
		SetWinner();
	}
}

void Dealer::NextPlayer()
{
	Player* temp = currentPlayer;
	currentPlayer = otherPlayer;
	otherPlayer = temp;

}


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
	roundFinished = true;
}


int Dealer::HowManyNotEven()
{
	int notEven = otherPlayer->creditsSpent - currentPlayer->creditsSpent;
	
	return notEven;
}

void Dealer::Pass()
{
	if (currentPlayer==&computer) //jesli wskaznik ma ten sam adres to wskazuja na to samo
	{
		//kasa do czlowieka
		human.credits += credits;

	}
	else if(currentPlayer==&human)
	{
		//kasa do kompa
		computer.credits += credits;
	}

	roundFinished = true;
}




