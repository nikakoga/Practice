#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"


class Player
{
public:
	Player(Deck& _deck);

	int credits = 100;
	std::string name;
	std::vector<Card> hand;
	Deck& deck;

	//Take card.
	virtual void TakeCard();
	virtual void PayUp(int amount);
	virtual bool ChooseToMatchOrFold(int amount);

	
};

	


