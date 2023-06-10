#pragma once
#include <string>
#include <iostream>
#include "CardValue.h"

class Card
    
{
public:

    Card(std::string c_value, std::string c_colour);
    void ShowCard();
    std::string GetColour();
    std::string GetValue();
    //zrobic get value as int uzywajac do tego enuma

private:
    std::string colour;
    std::string value;
};

