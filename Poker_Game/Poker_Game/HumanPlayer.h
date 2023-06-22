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

    int Raise() override;
    
    void TakeCard() override;

    bool PayUp(int amount, std::string context) override;

    void ShowHand();

    void ShowCreditsInfo() override;

    

   
    
};

