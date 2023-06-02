#pragma once
#include "Deck.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

class Card : public Deck
    
{
public:

    Card(const Deck& deck);
    void ShowCard();

private:
    std::string colour;
    std::string value;
};

