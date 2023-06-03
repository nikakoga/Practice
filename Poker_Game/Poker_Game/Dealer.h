#pragma once
#include "Player.h"

class Dealer : public Player
{

public:
	Dealer(Deck& deck) : Player(deck) {}

	void PlayTurn() override
	{
		// Logika gry dla dealera
	}

	protected:

	void Take_card();
	Deck deck;

	std::string name;
	std::vector<Card> hand;
	int credits;
	
};

