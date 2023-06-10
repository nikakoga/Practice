#include "Card.h"

Card::Card(std::string c_value, std::string c_colour)
{
    colour = c_colour;
    value = c_value;
}

void Card::ShowCard()
{
    
    std::cout<< value <<" "<< colour << std::endl << std::endl;
}

std::string Card::Get_colour()
{
    return colour;
}

std::string Card::Get_value()
{
    return value;
}

//CardValue c = A;
