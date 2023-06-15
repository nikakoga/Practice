#pragma once
#include <unordered_set>
#include "Card.h"
#include "Deck.h"


class Player
{
public:
	Player(Deck& _deck);

	int credits = 100;
	std::string name;
	std::vector<Card> hand;
	std::unordered_set<Card> bestCombination;
	Deck& deck;

	//Take card.
	virtual void TakeCard();
	virtual void PayUp(int amount);
	virtual bool ChooseToMatchOrFold(int amount); 
    void GenerateCombinations(int howManyToPick);
	int FindBestCombination();

private:
    void generateCombinationsUtil(std::vector<bool>& combinationMask, int index, int howManyToPick) {
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

    void RateCombination(const std::vector<bool>& combinationMask) {
        std::vector<Card> combination;
        for (size_t i = 0; i < hand.size(); ++i) {
            if (combinationMask[i]) {
                combination.push_back(hand[i]);
            }
        }

        // Calculate combination score
        for (const auto& card : combination) {
            //tutaj przyznawanie punktow
        }
        
    }

	
};

	
   



