#pragma once
#include "Deck.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

class Card
    
{
public:

    Card(const Deck& deck);
    void ShowCard();
    //Card Get_card();

private:
    std::string colour;
    std::string value;
};

