#pragma once
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Dealer : public Player
{

	//nie jestem pewna czy on powinien dziedziczyc z Playera bo w konstruktorze powinien dostac graczy
public:
	Dealer(Deck& deck, HumanPlayer& _human, ComputerPlayer& _computer ); 

	int currentPlayer=0;
	int whoStart = 1;

	HumanPlayer& human;
	ComputerPlayer& computer;
	int creditsFromHuman;
	int cresitsFromComputer;
	

	void TakeCard() override
	{
		//0. sprawdza czy oboje gracze wylozyli na stol tyle samo
		while (!CreditCheck())
		{
			int toPay = HowManyNotEven();
			if (currentPlayer = 1)
			{
				if (human.ChooseToMatchOrFold(toPay))
				{
					//pobieranie kasy
				}
				else
				{
					Pass();
				}
			}
			else
			{
				//funkcja decydujaca czy dolozyc czy spasowac u komputera
			}
		}
		//1. doklada karte
		hand.push_back(deck.GetCard());
		//2. wyswietla stol
		ShowTable();	
	}

	void ShowTable();

	void SetWinner()
	{
		//porownuje ktora reka jest silniejsza
	}

	bool CreditCheck();

	int HowManyNotEven()
	{
		int notEven = 0;
		if (creditsFromHuman > cresitsFromComputer)
		{
			notEven = creditsFromHuman - cresitsFromComputer;
		}
		else
		{
			notEven = cresitsFromComputer - creditsFromHuman;
		}
		return notEven;
	}

	void Pass()
	{
		if (currentPlayer == 1)
		{
			//kasa do kompa
			
		}
		else
		{
			//kasa do czlowieka
		}
		
	}

	

};

