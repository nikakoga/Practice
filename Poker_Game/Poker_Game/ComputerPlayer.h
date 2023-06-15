#pragma once
#include "Player.h"
class ComputerPlayer :
    public Player
{
    
    public:
        ComputerPlayer(Deck& deck);

        int credits = 1000;
        int creditsSpend = 0; //powinno sie przydac do strategi gry, ale jak nie to usun z PayUp tez

        void PayUp(int amount, std::string context) override;
        void Raise() override;

        bool ChooseToMatchOrFold(int amount) override
        {
            //funkcja decyduj¹ca czy dolozyc czy spasowac
            return true;
        }
        
        //funkcja decydujaca czy podbic (jesli podbicie to wypisanie na ekran)
        bool ChooseRaise(int amount) override;

        
       
};

