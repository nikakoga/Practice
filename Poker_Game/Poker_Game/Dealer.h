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
	Player* otherPlayer;
	HumanPlayer& human;
	ComputerPlayer& computer;

	
	
	void SetTable();
	void ShowTable();

	void CheckAmount();
	int HowManyNotEven();
	void PayToWinner(Player * winner);

	void GiveCard(); 

	void Turn();
	void NextPlayer();

	void SetWinner();

	void Pass();

	

};

