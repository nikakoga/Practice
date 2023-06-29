#pragma once
#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#include "Card.h"



class Deck
{
public:
	Deck();
	
	void ShowAvailable();
	void ShuffleDeck();
	void CreateDeck();
	Card GetCard();
	void NewRound();

private:
	std::vector<Card> deck;
	void ClearDeck();

};

