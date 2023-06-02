#pragma once
//#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Deck
{

public:

	Deck();

	void Show_available();


protected:
	//std::unordered_map<int, std::vector<std::string>> cards;
	//std::vector<std::string> not_available = cards.at(0);
	std::vector<std::string> available;
	std::vector<std::string> cards;

	void Update_deck(std::string card);

	
};


//void operator - (std::string used)
//{
//	not_available = cards.at(0);
//	std::vector<std::string> available = cards.at(1);

//	//finding card to delete from available
//	auto iter = std::find(available.begin(), available.end(), used);
//	if (iter != available.end()) {
//		available.erase(iter);
//	}
//	else
//	{
//		// TO DO THROW EXCEPTION
//	}

//	//mark card as used
//	not_available.push_back(used);
//	cards[0] = not_available;
//	cards[1] = available;
//}

/*void Update_deck(std::string used)
{
	cards - used;
}*/
