#include "Card.h"

Card::Card(const Deck& deck)
{
    int random = std::rand() % (available.size() - 1);
    std::string card = available[random];
    value = card[0];
    colour = card.substr(1, card.length() - 1); 
    Update_deck(card);
}

void Card::ShowCard()
{
    std::cout <<"Wylosowalas "<< value << colour << std::endl<<std::endl;
}
