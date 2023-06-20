#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Deck& deck) : Player(deck)
{
	name = "Computer";
	creditsOnTable = 0;
	credits = 1000;
	finished = false;
	lostRound = false;
	bankrupt = false;
}

void ComputerPlayer::PayUp(int amount, std::string context)
{
	if (credits >= amount)
	{
		credits -= amount;
		creditsOnTable += amount;
		std::cout << name << " paid " << amount << " to " << context << "\n"<<"\n";
	}
	else
	{
		//przegrana
		lostRound = true;
	}
}

bool ComputerPlayer::ChooseToMatchOrFold(int amount)
{
	//funkcja decydująca czy dolozyc czy spasowac
	//ZMIEN POTEM NA RAZIE NA SZTYWNO JEST NA TAK I PLACENIE
	PayUp(amount, "match");
	return true;
}

bool ComputerPlayer::ChooseRaise()
{
	bool raise = true;
	//ZMIEN POTEM NA RAZIE NA SZTYWNO JEST NA NIE I KONIEC TURY
	if (!raise)
	{
		std::cout << name << " dont raise" << "\n";
		finished = true;
		return false;
	}

	if (raise)
	{
		Raise();
		finished = false;
		return false;
	}
}


void ComputerPlayer::Raise()
{
	int number = 20;
	PayUp(number, "raise");
}
