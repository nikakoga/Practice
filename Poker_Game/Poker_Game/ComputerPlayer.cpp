#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Deck& deck) : Player(deck)
{
	name = "computer";
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
		creditsOnTable += amount;  //moze potem do usuniecia aby chociaz jedna funkcja dzialala calkowicie z bazowej klasy
	}
	else
	{
		//przegrana
		lostRound = true;
	}
}

void ComputerPlayer::Raise()
{
	std::cout << "Computer raise " << "\n";
}

bool ComputerPlayer::ChooseRaise()
{
	return false;
}
