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
	Player* startPlayer;

	bool matched;
	int startPay = 100;
	HumanPlayer& human;
	ComputerPlayer& computer;

	int creditsOnTable = 0;
	
	void SetTable();
	void ShowTable();
	void ShowCreditsInfo()override;

	void OptionMatchOrFold();
	void OptionRaise();

	int HowManyNotEven();
	void PayStartFee();
	void PayToWinner(Player * winner);

	void GiveCard(); 
	void NextPlayer();
	void StartPlayerSwitch();
	void SetOtherPlayer();

	void SetWinner();
	void AnounceWinner(Player* winner);

	void Pass();

	void Clean();

};

