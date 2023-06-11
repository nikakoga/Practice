// Poker_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Dealer.h"

int main()
{
    srand(time(0));

    Deck deck;
    deck.Show_available();
   // deck.ShuffleDeck();
    Card random = deck.GetCard();
    random.ShowCard();
    deck.Show_available();
    HumanPlayer human(deck);
    ComputerPlayer comp(deck);
    
    
}


