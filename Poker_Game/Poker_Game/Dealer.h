#pragma once
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Dealer : public Player
{

	//nie jestem pewna czy on powinien dziedziczyc z Playera bo w konstruktorze powinien dostac graczy
public:
	Dealer(Deck& deck, HumanPlayer& _human, ComputerPlayer& _computer ); 

	Player* currentPlayer;

	HumanPlayer& human;
	ComputerPlayer& computer;
	int creditsFromHuman=0;
	int creditsFromComputer=0;
	

	void GiveCard(); 

	void SetTable();

	void ShowTable();

	void SetWinner();

	bool CreditCheck();

	int HowManyNotEven();

	void Pass();

	

};

