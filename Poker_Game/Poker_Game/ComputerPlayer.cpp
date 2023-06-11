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
		creditsSpend += amount; 
	}
	else
	{
		//przegrana
	}
}
