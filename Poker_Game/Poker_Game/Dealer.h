#pragma once
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Dealer : public Player
{

	//nie jestem pewna czy on powinien dziedziczyc z Playera bo w konstruktorze powinien dostac graczy
public:
	Dealer(Deck& deck) : Player(deck) {} //w konstruktorze powinno sie mu podawac chyba tez gracza komputerowego i human
	Deck deck;

	int currentPlayer=1;
	

	void PlayTurn() override
	{
		// Logika gry dla dealera o ile w ogole on ma uzywac tej funkcji, ale raczej nie
	}

	void TakeCard() override
	{
		//0. sprawdza czyja kolej i komu ma dac karte
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


	//name = "dealer";
	//std::vector<Card> hand;
	//credits;
	
};

