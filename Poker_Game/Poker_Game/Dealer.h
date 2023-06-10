#pragma once
#include "Player.h"

class Dealer : public Player
{

public:
	Dealer(Deck& deck) : Player(deck) {}
	Deck deck;

	void PlayTurn() override
	{
		// Logika gry dla dealera
	}

	void TakeCard() override
	{
		//1. sprawdza czy oboje gracze wylozyli na stol tyle samo
		//2. doklada karte
		//3. wyswietla karte
	}

	//name = "dealer";
	//std::vector<Card> hand;
	//credits;
	
};

