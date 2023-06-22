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

bool ComputerPlayer::PayUp(int amount, std::string context)
{
	if (credits == 0)
	{
		bankrupt = true;
		return false;
	}
	else if (credits >= amount)
	{
		credits -= amount;
		creditsOnTable += amount;
		std::cout << name << " paid " << amount << " to " << context << "\n";
		return true;
	}
	else
	{
		//komputer nie podbije wiecej niz moze wiec jesli nie moze zaplacic to albo aby wystartowac albo aby dorownac
		bankrupt = true;
		return false; //CHYBA??
	}
}

bool ComputerPlayer::ChooseToMatchOrFold(int amount)
{
	//funkcja decyduj¹ca czy dolozyc czy spasowac
	//ZMIEN POTEM NA RAZIE NA SZTYWNO JEST NA TAK I PLACENIE
	Sleep();
	PayUp(amount, "match");
	return true;
}

bool ComputerPlayer::ChooseRaise()
{
	//ZMIEN POTEM NA RAZIE NA SZTYWNO JEST NA NIE I KONIEC TURY
	Sleep();
	if (!nextRaise)
	{
		std::cout << name << " dont raise" << "\n";
		finished = true;
		nextRaise = true; // !! POTEM DO WYWALENIA
		return false;
	}

	if (nextRaise)
	{
		finished = false;
		nextRaise = false; // !! POTEM DO WYWALENIA
		return true;
	}
}

void ComputerPlayer::Sleep()
{
	std::this_thread::sleep_for(std::chrono::seconds(2));
}


int ComputerPlayer::Raise()
{
	int number = 20;
	PayUp(number, "raise");
	return number;
}
