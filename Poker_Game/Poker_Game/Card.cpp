#include "Card.h"

Card::Card()
{
    int random = std::rand() % (available.size() - 1);
    std::string card = available[random];
    value = card[0];
    colour = card.substr(1, card.length() - 1); 
}

void Card::ShowCard()
{
    std::cout << value << colour << std::endl;
}
