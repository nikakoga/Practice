#pragma once
#include "Player.h"
#include <thread>
class ComputerPlayer :
    public Player
{
    
    public:
        ComputerPlayer(Deck& deck);

        bool PayUp(int amount, std::string context) override;
        int Raise() override;

        bool ChooseToMatchOrFold(int amount) override;
        //funkcja decydujaca czy podbic (jesli podbicie to wypisanie na ekran)
        bool ChooseRaise() override;

        bool nextRaise=true;

        void Sleep();

        
       
};

