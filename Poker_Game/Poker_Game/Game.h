#pragma once
#include "Dealer.h"


class Game
{
public:
	Game(Dealer& _dealer, HumanPlayer& _human, ComputerPlayer& _computer, Player* _startPlayer);

	int startPay = 10;
	
	Dealer & dealer;
	HumanPlayer& human;
	ComputerPlayer& computer;
	Player* startPlayer;
	
	void PayStartFee();
	void Play(); //ma sie dziac tutaj a nie w konstruktorze
	void Auctions(); 
	bool GameOver();
};

