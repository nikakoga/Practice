#include "ComputerPlayer.h"

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
