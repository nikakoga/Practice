#pragma once
#include "Player.h"
class HumanPlayer :
    public Player
{
public:
    HumanPlayer(Deck& deck) : Player(deck) {}

    bool ChooseToMatchOrFold(int amount) override;
    
    void TakeCard() override;

    void ShowHand();

    int SafeRespond();
    
};

