#include "Round.h"

Round::Round(Dealer& _dealer, HumanPlayer& _human, ComputerPlayer& _computer, Player* _currentPlayer) 
	: dealer(_dealer), human(_human), computer(_computer)
{
	startPlayer = _currentPlayer;
	dealer.currentPlayer = startPlayer;
	
}

void Round::PayStartFee()
{
	human.PayUp(startPay,"start");
	computer.PayUp(startPay,"start");
}

void Round::Play()
{
	while (!human.lost || !computer.lost) //dopoki komputer lub czlowiek nie przegra
	{
		std::cout << startPlayer->name << " starts" << "\n";
		PayStartFee();
		Auctions();
		dealer.SetTable();
		Auctions();
		dealer.GiveCard();
		Auctions();
		dealer.GiveCard();
		Auctions();
		//ocena kombinacji
		//porownanie
		//kasa do wygranego
	}
	if (human.lost)


	dealer.Clean();
}

void Round::Auctions()
{
	while (!human.finished && !computer.finished)
	{
		dealer.OptionMatchOrFold();
		dealer.OptionRaise();
		dealer.NextPlayer();
	}
}
