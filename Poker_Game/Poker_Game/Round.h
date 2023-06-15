#pragma once
#include "Dealer.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Round
{
	Round(Dealer& _dealer, HumanPlayer& _human, ComputerPlayer& _computer);

	int startPay = 10;
	

	void PayStartFee();
};

