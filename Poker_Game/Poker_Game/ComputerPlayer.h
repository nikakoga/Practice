#pragma once
#include "Player.h"
#include <thread>
class ComputerPlayer :
    public Player
{
    
    public:
        ComputerPlayer(Deck& deck);

        void PayUp(int amount, std::string context) override;
        void Raise() override;

        bool ChooseToMatchOrFold(int amount) override;
        //funkcja decydujaca czy podbic (jesli podbicie to wypisanie na ekran)
        bool ChooseRaise() override;

        bool nextRaise=true;

        void Sleep();

        
       
};

