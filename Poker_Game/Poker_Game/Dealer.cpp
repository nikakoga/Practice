#include "Dealer.h"

Dealer::Dealer(Deck& _deck)
{
    deck = _deck;
}


Dealer::Take_card()
{
    Card card = deck.Get_card();
    hand.push_back(card);
    
}
