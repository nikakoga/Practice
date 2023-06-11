#pragma once
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Dealer : public Player
{

	//nie jestem pewna czy on powinien dziedziczyc z Playera bo w konstruktorze powinien dostac graczy
public:
	Dealer(Deck& deck, HumanPlayer& _human, ComputerPlayer& _computer ); 

	enum PlayerType {
		Human,
		Computer
	};
	PlayerType currentPlayer = Human;
	PlayerType whoStarte = Human;

	HumanPlayer& human;
	ComputerPlayer& computer;
	int creditsFromHuman=0;
	int creditsFromComputer=0;
	

	void TakeCard() override;

	void ShowTable();

	void SetWinner();

	bool CreditCheck();

	int HowManyNotEven();

	void Pass();

	

};

