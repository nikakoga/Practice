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

	void Show_available();
	void Shuffle_deck();
	//void Update_deck(std::string card);

	std::vector<std::string> all_existing_cards;
	std::vector<Card> cards;

	Card Get_card();
};

