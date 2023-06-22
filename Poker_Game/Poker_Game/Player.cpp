#include "Player.h"

Player::Player(Deck& _deck) : deck(_deck) 
{
	
}

void Player::TakeCard()
{
	hand.push_back(deck.GetCard());
}

bool Player::PayUp(int amount, std::string context)
{
	return false;
}

int Player::Raise()
{
	return 0;
}


bool Player::ChooseToMatchOrFold(int amount)
{
	return false;
}

//void Player::Pass()
//{
//	std::cout << name << " folds" << "\n";
//	lostRound = true;
//	finished = true;
//}

bool Player::ChooseRaise()
{
	return false;
}

void Player::ShowCreditsInfo()
{
}

void Player::CleanAfterRound()
{
	lostRound = false;
	creditsOnTable = 0;
	hand.clear();
	finished = false;
}

void Player::GenerateCombinations(int howManyToPick)
{
	std::vector<bool> combinationMask(hand.size(), false);
	generateCombinationsUtil(combinationMask, 0, howManyToPick);
}

int Player::FindBestCombination()
{

	return 0;
}

void Player::generateCombinationsUtil(std::vector<bool>& combinationMask, int index, int howManyToPick)
{
	if (howManyToPick == 0) {
		RateCombination(combinationMask);
		return;
	}

	if (index >= hand.size()) {
		return;
	}

	// Wybierz aktualn¹ kartê do kombinacji
	combinationMask[index] = true;
	generateCombinationsUtil(combinationMask, index + 1, howManyToPick - 1);

	// Nie wybieraj aktualnej karty do kombinacji
	combinationMask[index] = false;
	generateCombinationsUtil(combinationMask, index + 1, howManyToPick);
}
