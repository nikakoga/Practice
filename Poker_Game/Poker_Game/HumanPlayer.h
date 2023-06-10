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
    void TakeCard() override
    {
        // 1. uruchamia dealera zeby dal karte
        //2. dodaje karte do reki
        //3.wyswietla karte
    }
};

