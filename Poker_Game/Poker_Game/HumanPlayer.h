#pragma once
#include "Player.h"
class HumanPlayer :
    public Player
{
public:

    bool bankrupt = false;
    HumanPlayer(Deck& deck);

    int SafeChooseBetweenTwo();

    bool IsInteger(std::string input);

    bool ChooseToMatchOrFold(int amount) override;

    bool ChooseRaise() override;

    void Raise() override;
    
    void TakeCard() override;

    void PayUp(int amount, std::string context);

    void ShowHand();

   
    
};

