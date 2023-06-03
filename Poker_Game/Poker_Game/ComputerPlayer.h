#pragma once
#include "Player.h"
class ComputerPlayer :
    public Player
{
    
    public:
        ComputerPlayer(Deck & deck) : Player(deck) {}

        void PlayTurn() override
        {
            // Logika gry dla gracza komputerowego
        }
    
};

