#pragma once
#include "Player.h"
class HumanPlayer :
    public Player
{
public:
    HumanPlayer(Deck& deck) : Player(deck) {}

    void PlayTurn() override
    {
        // Logika gry dla gracza cz³owieka
    }
};

