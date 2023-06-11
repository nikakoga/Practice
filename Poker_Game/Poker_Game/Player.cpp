#include "Player.h"

Player::Player(Deck& _deck) : deck(_deck) {}

void Player::TakeCard()
{
	hand.push_back(deck.GetCard());

}

void Player::PayUp(int amount)
{
	if (credits >= amount)
	{
		credits -= amount;
	}
	else
	{
		//przegrana
	}
	
}

bool Player::ChooseToMatchOrFold(int amount)
{
	return false;
}
