#pragma once
#include "Dealer.h"


class Round
{
public:
	Round(Dealer& _dealer, HumanPlayer& _human, ComputerPlayer& _computer);

	int startPay = 10;
	
	Dealer & dealer;
	HumanPlayer& human;
	ComputerPlayer& computer;
	
	void PayStartFee();
	void Play(); //ma sie dziac tutaj a nie w konstruktorze
	void Turn(); 
};

