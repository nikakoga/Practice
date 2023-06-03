#include "Card.h"

Card::Card(std::string c_value, std::string c_colour)
{
   /* 
    int random = std::rand() % (available.size() - 1);
    std::string card = available[random];
    value = card[0];
    colour = card.substr(1, card.length() - 1); 
    Update_deck(card);
    
    */
    colour = c_colour;
    value = c_value;
}

void Card::ShowCard()
{
    std::cout <<"Wylosowalas "<< value << colour << std::endl<<std::endl;
}

std::string Card::Get_colour()
{
    return colour;
}

std::string Card::Get_value()
{
    return value;
}

