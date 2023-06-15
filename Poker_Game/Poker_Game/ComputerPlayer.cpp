#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer(Deck& deck) : Player(deck)
{
	name = "computer";
}

void ComputerPlayer::PayUp(int amount)
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
