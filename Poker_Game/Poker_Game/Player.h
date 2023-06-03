#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"


class Player
{
public:
	Player(Deck& _deck);

	virtual void PlayTurn() = 0;

protected:
	Deck& deck;
};

	//std::string Take_card()
//protected:
//	std::string name;
//	std::vector<Card> hand;
//	int credits;


