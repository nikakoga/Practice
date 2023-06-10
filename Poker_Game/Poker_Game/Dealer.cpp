#include "Dealer.h"

Dealer::Dealer(Deck& _deck, HumanPlayer& _human, ComputerPlayer& _computer)
{
	human = _human;
	computer = _computer;
	name = "dealer";
	credits = 0;
}
