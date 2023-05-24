#include "Deck.h"

Deck::Deck()
{
			std::vector<std::string> card_colours = { "club","spade","heart","diamond" };
			std::vector<std::string> card_values = { "1","2","3","4","5","6","7","8","9","10","J","Q","K","A" };
			std::vector<std::string> deck;

			for (std::string colour : card_colours)
			{
				for (std::string value : card_values)
				{
					deck.push_back(value +" " +colour);
					std::cout << value +" "+ colour << std::endl;
				}
			}
			Deck::cards[1] = deck;	
}

		