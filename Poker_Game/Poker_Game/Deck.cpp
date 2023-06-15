#include "Deck.h"

Deck::Deck()
{
	CreateDeck();
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
	std::random_device rd;
	std::mt19937 rng(rd()); // jakis bardziej zaawansowany generator liczb losowych niz std::default_random_engine, nie trzeba robic srand
	std::shuffle(std::begin(deck), std::end(deck), rng);
}

void Deck::CreateDeck()
{
	std::vector<std::string> card_colours = { "club","spade","heart","diamond" };
	std::vector<std::string> card_values = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
	

	for (std::string colour : card_colours)
	{
		for (std::string value : card_values)
		{
			Card new_card(value, colour); 
			deck.push_back(new_card);
		}
	}
	ShuffleDeck();
}


Card Deck::GetCard()
{
	Card drawnCard = deck.back();
	deck.pop_back();
	return drawnCard;
}

void Deck::ClearDeck()
{
	deck.clear();
}





