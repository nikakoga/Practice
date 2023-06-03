#pragma once
#include <string>
#include <vector>
//ma_byc_wityualna_docelowo
class Player
{
public:
	Player(std::string ID);
	//std::string Take_card()
private:
	std::string name;
	std::vector<std::string> hand;
	int credits;
};

