#pragma once
#include <unordered_set>
#include "Card.h"
#include "Deck.h"


class Player
{
public:
	Player(Deck& _deck);

	int credits = 1000;
	std::string name;
	std::vector<Card> hand;
	//std::unordered_set<Card> bestCombination; //NAPRAW BO WYKRZACZA
	Deck& deck;

	//Take card.
	virtual void TakeCard();
    virtual void PayUp(int amount, std::string context);
    virtual void Raise();
	virtual bool ChooseToMatchOrFold(int amount); 
    virtual bool ChooseRaise(int amount);


    void GenerateCombinations(int howManyToPick);
	int FindBestCombination();

private:
    void generateCombinationsUtil(std::vector<bool>& combinationMask, int index, int howManyToPick);

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

	
   



