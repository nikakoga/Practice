// Poker_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Game.h"

int main()
{

    Deck deck;
    /*deck.Show_available();
    Card random = deck.GetCard();
    random.ShowCard();
    deck.Show_available();*/

    HumanPlayer human(deck);
    ComputerPlayer computer(deck);
    Dealer dealer(deck, human, computer);
    Player* start = &human; //KTO ZACZYNA
    Game game(dealer, human, computer,start);
    game.Play();
    
    
}


