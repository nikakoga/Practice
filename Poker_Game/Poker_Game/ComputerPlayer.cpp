#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Deck& deck) : Player(deck)
{
	name = "computer";
	creditsOnTable = 0;
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
		lost = true;
	}
}

void ComputerPlayer::Raise()
{
	
}

bool ComputerPlayer::ChooseRaise()
{
	return false;
}
