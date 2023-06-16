// Poker_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Round.h"

int main()
{

    Deck deck;
    /*deck.Show_available();
    Card random = deck.GetCard();
    random.ShowCard();
    deck.Show_available();*/

    HumanPlayer human(deck);
    ComputerPlayer comp(deck);
    Dealer dealer(deck, human, comp);
    Player* current = &human;
    Round round(dealer, human, comp,current);
    
    
}


