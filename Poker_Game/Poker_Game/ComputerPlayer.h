#pragma once
#include "Player.h"
class ComputerPlayer :
    public Player
{
    
    public:
        ComputerPlayer(Deck& deck);

        int creditsSpend = 0; //powinno sie przydac do strategi gry, ale jak nie to usun z PayUp tez

        void PayUp(int amount) override;

        bool ChooseToMatchOrFold(int amount) override
        {
            //funkcja decyduj¹ca czy dolozyc czy spasowac
            return false;
        }

        
        //funkcja decydujaca czy podbic (jesli podbicie to wypisanie na ekran)

        
       
};

