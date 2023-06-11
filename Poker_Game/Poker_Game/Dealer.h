#pragma once
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Dealer : public Player
{

	//nie jestem pewna czy on powinien dziedziczyc z Playera bo w konstruktorze powinien dostac graczy
public:
	Dealer(Deck& deck, HumanPlayer& _human, ComputerPlayer& _computer ); 

	int currentPlayer=0;
	int whoStart = 1;

	HumanPlayer& human;
	ComputerPlayer& computer;
	int creditsFromHuman;
	int cresitsFromComputer;
	

	void TakeCard() override;

	void ShowTable();

	void SetWinner();

	bool CreditCheck();

	int HowManyNotEven();

	void Pass();

	

};

