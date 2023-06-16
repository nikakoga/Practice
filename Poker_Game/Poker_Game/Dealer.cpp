#include "Dealer.h"

Dealer::Dealer(Deck& _deck, HumanPlayer& _human, ComputerPlayer& _computer) 
	: Player(_deck), human(_human), computer(_computer)
{
	name = "dealer";
	credits = 0;
	creditsOnTable = 0;
	finished = false;
}

void Dealer::OptionMatchOrFold()
{
	//sprawdza czy aktualny gracz wylozyl odpowiednio duzo
	while (currentPlayer->creditsOnTable < otherPlayer->creditsOnTable)
	{
		int toPay = HowManyNotEven();
		//jesli nie to wybiera czy doplacic
		if (!currentPlayer->ChooseToMatchOrFold(toPay)) //jesli spassuje
		{
			currentPlayer->PayUp(toPay, "match");
			
		}
		//czy spasowac
		else
		{
			Pass();
			//powinna zakonczyc sie tura
			break;
		}
	}
	
	
}

void Dealer::OptionRaise()
{
	if (currentPlayer->ChooseRaise())
	{
		currentPlayer->Raise();
	}
}


void Dealer::GiveCard()
{
	TakeCard();
	ShowTable();
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
	
}


int Dealer::HowManyNotEven()
{
	int notEven = otherPlayer->creditsOnTable - currentPlayer->creditsOnTable;
	return notEven;
}

void Dealer::PayToWinner(Player * winner) //nie wiem czy dziala
{
	creditsOnTable = human.creditsOnTable + computer.creditsOnTable;
	winner->credits += creditsOnTable;
}

void Dealer::Pass()
{
	//koniec tury
	human.finished = true;
	computer.finished = true;

	if (currentPlayer==&computer) //jesli wskaznik ma ten sam adres to wskazuja na to samo
	{
		//komp przegral
		computer.lost = true;
	}
	else if(currentPlayer==&human)
	{
		//czlowiek przegral
		human.lost = true;
	}
}

void Dealer::Clean()
{
	CleanAfterRound();
	human.CleanAfterRound();
	computer.CleanAfterRound();
	deck.NewRound();
}




