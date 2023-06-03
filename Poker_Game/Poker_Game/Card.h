#pragma once
#include "Deck.h"
#include <cstdlib>
#include <cstdio>
#include <ctime>

class Card
    
{
public:

    Card(std::string c_value, std::string c_colour);
    void ShowCard();
    //Card Get_card();
    std::string Get_colour;
    std::string Get_value;

private:
    std::string colour;
    std::string value;
};

