#pragma once
#include <string>
#include <vector>
class Player
{
public:
	Player(std::string ID);
	//std::string Take_card()
private:
	std::string name;
	std::vector<std::string> hand;
};

