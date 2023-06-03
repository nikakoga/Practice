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
					deck.push_back(value +" " +colour); //creating string for vector of strings

					Card new_card(value, colour); //creating objects for vector of objects
					cards.push_back(new_card);
				}
			}

			Deck::all_existing_cards = deck;
			
}

void Deck::Show_available()
{
	std::cout << "Dostepne karty" << std::endl;
	for (auto card : cards)
	{
		std::cout << card.Get_value()<<card.Get_colour() << std::endl;
	}
	std::cout << std::endl;
}

void Deck::Shuffle_deck()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(cards), std::end(cards), rng);
}


Card Deck::Get_card()
{
	Card drawnCard = cards.back();
	cards.pop_back();
	return drawnCard;
	
}

//void Deck::Update_deck(std::string card)
//{
//	 auto it = std::find(cards.begin(), cards.end(), card);
//	
//	if (it!= cards.end())
//	{
//		cards.erase(it);
//	}
//}




