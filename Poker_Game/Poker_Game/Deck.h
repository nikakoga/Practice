#pragma once
#include <vector>
#include <string>
#include <iostream>
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
	std::vector<Card> deck;

	void Show_available();
	void ShuffleDeck();
	void CreateDeck();
	

	Card Get_card();

};

