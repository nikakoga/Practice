#pragma once
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Dealer : public Player
{

	//nie jestem pewna czy on powinien dziedziczyc z Playera bo w konstruktorze powinien dostac graczy
public:
	Dealer(Deck& deck, HumanPlayer& _human, ComputerPlayer& _computer ); 

	int currentPlayer=1;
	HumanPlayer& human;
	ComputerPlayer& computer;
	
	

	void PlayTurn() override
	{
		// Logika gry dla dealera o ile w ogole on ma uzywac tej funkcji, ale raczej nie
	}

	void TakeCard() override
	{
		//0. sprawdza czyja kolej i komu ma dac karte
		if (currentPlayer = 1)
		{
			human.TakeCard();
		}
		else
		{
			computer.TakeCard();
		}
		//1. sprawdza czy oboje gracze wylozyli na stol tyle samo
		//2. doklada karte
		//3. wyswietla karte
	}

	void SetWinner()
	{
		//porownuje ktora reka jest silniejsza
	}

	void Pass()
	{

	}

};

