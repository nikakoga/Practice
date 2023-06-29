#pragma once
#include <unordered_set>
#include "Card.h"
#include "Deck.h"


class Player
{
public:
	Player(Deck& _deck);

    bool finished = false;
    bool bankrupt = false;
    bool lostRound = false;

	int credits = 1000;
    int creditsOnTable = 0;
	std::string name;
	std::vector<Card> hand;
    
	std::vector<Card> bestCombination; //NAPRAW BO WYKRZACZA // albo dopisz operator porownania dla Card albo przerob na inty
	Deck& deck;

	virtual void TakeCard();
    virtual bool PayUp(int amount, std::string context);
    virtual int Raise();
	virtual bool ChooseToMatchOrFold(int amount); 
    virtual bool ChooseRaise();
    virtual void ShowCreditsInfo();

    void CleanAfterRound();
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