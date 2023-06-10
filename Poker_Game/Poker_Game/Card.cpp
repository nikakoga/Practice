#include "Card.h"

Card::Card(std::string c_value, std::string c_colour)
{
    colour = c_colour;
    value = c_value;
}

void Card::ShowCard()
{
    
    std::cout << value << " " << colour << "\n";

}

std::string Card::GetColour()
{
    return colour;
}

std::string Card::GetValue()
{
    return value;
}

//CardValue c = A;
