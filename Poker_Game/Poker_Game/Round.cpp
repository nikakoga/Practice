#include "Round.h"

Round::Round(Dealer& _dealer, HumanPlayer& _human, ComputerPlayer& _computer) 
	: dealer(_dealer), human(_human), computer(_computer)
{
	
	while (!human.lost||!computer.lost) //dopoki komputer lub czlowiek nie przegra
	{
		PayStartFee();
		dealer.SetTable();
	}
	if (human.lost)


	dealer.Clean();
	
}

void Round::PayStartFee()
{
	human.PayUp(startPay,"start");
	computer.PayUp(startPay,"start");
}
