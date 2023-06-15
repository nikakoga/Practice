#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Deck& deck) : Player(deck)
{
	name = "computer";
}

void ComputerPlayer::PayUp(int amount, std::string context)
{
	if (credits >= amount)
	{
		credits -= amount;
		creditsSpend += amount;  //moze potem do usuniecia aby chociaz jedna funkcja dzialala calkowicie z bazowej klasy
	}
	else
	{
		//przegrana
	}
}

void ComputerPlayer::Raise()
{
	
}

bool ComputerPlayer::ChooseRaise(int amount)
{
	return false;
}
