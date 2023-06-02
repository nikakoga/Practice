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
					//std::cout << value +" "+ colour << std::endl; // to show card
				}
			}
			
			Deck::available = deck;
			Deck::cards = deck;
}

void Deck::Show_available()
{
	for (auto card : available)
	{
		std::cout << card << std::endl;
	}
}

void Deck::Update_deck(std::string card)
{
	auto pos = std::find(available.begin(), available.end(), card);
	
	if (pos != available.end())
	{
		available.erase(pos);
	}
}



