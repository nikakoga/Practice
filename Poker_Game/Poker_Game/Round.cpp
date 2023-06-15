#include "Round.h"

Round::Round(Dealer& _dealer, HumanPlayer& _human, ComputerPlayer& _computer) 
	: dealer(_dealer), human(_human), computer(_computer)
{
	PayStartFee();
	dealer.SetTable();
}

void Round::PayStartFee()
{
	human.PayUp(startPay,"start");
	computer.PayUp(startPay);
}
