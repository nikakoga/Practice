#pragma once
#include "Dealer.h"


class Round
{
public:
	Round(Dealer& _dealer, HumanPlayer& _human, ComputerPlayer& _computer);

	int startPay = 10;
	bool finished = false;
	
	Dealer & dealer;
	HumanPlayer& human;
	ComputerPlayer& computer;
	

	void PayStartFee();
	void Play();
};
