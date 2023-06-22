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
	ShowCreditsInfo();

	matched = false;
	//sprawdza czy aktualny gracz wylozyl odpowiednio duzo
	while (currentPlayer->creditsOnTable < otherPlayer->creditsOnTable)
	{
		int toPay = HowManyNotEven();
		//jesli nie to wybiera czy doplacic
		if (!currentPlayer->ChooseToMatchOrFold(toPay)) // jesli nie chce doplacic
		{
			Pass();
			//powinna zakonczyc sie tura
			break;
		}
		matched = true; // CD 1 jesli gracz zmatchowal
	}
}

void Dealer::OptionRaise()
{
	int raised;
	if (currentPlayer->ChooseRaise())
	{
		raised = currentPlayer->Raise();
		if (raised == 0) //CD 2 podbil o 0 
		{
			currentPlayer->finished = true;
			otherPlayer->finished = true; //to oznacza Check i konczy ture
		}
	}
	else //CD 2 lub po prostu nie podbil
	{
		if (matched)
		{
			currentPlayer->finished = true;
			otherPlayer->finished = true; //to oznacza Check i konczy ture
		}
	}
}


void Dealer::GiveCard()
{
	if (!human.lostRound && !computer.lostRound)
	{
		TakeCard();
		ShowTable();
	}
}


void Dealer::NextPlayer()
{
	Player* temp = currentPlayer;
	currentPlayer = otherPlayer;
	otherPlayer = temp;	
}

void Dealer::StartPlayerSwitch()
{
	if (startPlayer == &human)
	{
		startPlayer = &computer;
	}
	else
	{
		startPlayer = &human;
	}
	currentPlayer = startPlayer;
	SetOtherPlayer();
}

void Dealer::SetOtherPlayer()
{
	if (startPlayer == &human)
	{
		otherPlayer = &computer;
	}
	else
	{
		otherPlayer = &human;
	}
}


void Dealer::SetTable()
{
	if (!human.lostRound && !computer.lostRound)
	{
		TakeCard();
		TakeCard();
		TakeCard();
		ShowTable();
	}
	
}

void Dealer::ShowTable()
{
	std::cout << "\n"<<"Table contains : " << "\n";
	for (Card card : hand)
	{
		card.ShowCard();
	}
	//std::cout << "\n";
}

void Dealer::ShowCreditsInfo()
{
	std::cout <<"\n"<< currentPlayer->name << " turn" << "\n";
	std::cout << "There is " << human.creditsOnTable + computer.creditsOnTable << " credits on Table" << "\n";
	currentPlayer->ShowCreditsInfo();
}

void Dealer::SetWinner()
{
	//porownuje ktora reka jest silniejsza
	//potrzeba stworzyc kombinacje z wszystkich kart
	
}

void Dealer::AnounceWinner(Player* winner)
{
	std::cout << winner->name << " wins !!!!!!!!!!!" << "\n";
}


int Dealer::HowManyNotEven()
{
	int notEven = otherPlayer->creditsOnTable - currentPlayer->creditsOnTable;
	return notEven;
}

void Dealer::PayStartFee()
{
	currentPlayer->PayUp(startPay, "start");
	otherPlayer->PayUp(startPay, "start");	
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
		computer.lostRound = true;
		Player * winner = &human;
		AnounceWinner(winner);
	}
	else if(currentPlayer==&human)
	{
		//czlowiek przegral
		human.lostRound = true;
		Player * winner = &computer;
		AnounceWinner(winner);
	}	
}

void Dealer::Clean()
{
	CleanAfterRound();
	human.CleanAfterRound();
	computer.CleanAfterRound();
	deck.NewRound();
}




