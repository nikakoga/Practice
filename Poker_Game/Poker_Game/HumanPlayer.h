#pragma once
#include "Player.h"
class HumanPlayer :
    public Player
{
public:

    
    HumanPlayer(Deck& deck);

    int SafeChooseBetweenTwo();

    bool IsInteger(std::string input);

    bool ChooseToMatchOrFold(int amount) override;

    bool ChooseRaise() override;

    void Raise() override;
    
    void TakeCard() override;

    void PayUp(int amount, std::string context);

    void ShowHand();

    void ShowCreditsInfo() override;

    void Pass();

   
    
};

