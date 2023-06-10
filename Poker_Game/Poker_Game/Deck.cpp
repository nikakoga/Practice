#include "Deck.h"

Deck::Deck()
{
	CreateDeck();
	ShuffleDeck();
}

void Deck::Show_available()
{
	std::cout << "Dostepne karty" << "\n";
	for (auto card : deck)
	{
		std::cout << card.GetValue()<<" "<<card.GetColour() << "\n";
	}
	std::cout << "\n"
;
}

void Deck::ShuffleDeck()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(deck), std::end(deck), rng);
}

void Deck::CreateDeck()
{
	std::vector<std::string> card_colours = { "club","spade","heart","diamond" };
	std::vector<std::string> card_values = { "1","2","3","4","5","6","7","8","9","10","J","Q","K","A" };
	

	for (std::string colour : card_colours)
	{
		for (std::string value : card_values)
		{
			Card new_card(value, colour); 
			deck.push_back(new_card);
		}
	}
}


Card Deck::GetCard()
{
	Card drawnCard = deck.back();
	deck.pop_back();
	return drawnCard;
}





