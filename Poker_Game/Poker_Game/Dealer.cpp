#include "Dealer.h"


void Dealer::Take_card()
{
    Card card = deck.Get_card();
    hand.push_back(card);
    
}
