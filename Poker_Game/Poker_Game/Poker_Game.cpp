// Poker_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Card.h"

int main()
{
    srand(time(0));

    Deck deck;
    deck.Show_available();
    //deck.Shuffle_deck();
    Card card(deck);
    card.ShowCard();
    deck.Show_available();
    
    
}


