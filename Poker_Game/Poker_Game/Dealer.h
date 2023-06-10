#pragma once
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class Dealer : public Player
{

	//nie jestem pewna czy on powinien dziedziczyc z Playera bo w konstruktorze powinien dostac graczy
public:
	Dealer(Deck& deck, HumanPlayer& _human, ComputerPlayer& _computer ); 

	int currentPlayer=1;

	HumanPlayer& human;
	ComputerPlayer& computer;
	int creditsFromHuman;
	int cresitsFromComputer;
	

	void PlayTurn() override
	{
		// Logika gry dla dealera o ile w ogole on ma uzywac tej funkcji, ale raczej nie
	}

	void TakeCard() override
	{
		//0. sprawdza czy oboje gracze wylozyli na stol tyle samo
		while (!CreditCheck())
		{
			if (currentPlayer = 1)
			{
				std::cout << "Do you want to:" << "\n" << "1 - match the current bet" << "\n" << "or" << "\n" << "2 - fold your hand";
				int respond = SafeRespond();
				if (respond == 1)
				{
					//dobijanie do stawki
				}
				else
				{
					//passowanie
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

	void Pass()
	{
		//wygrywa przeciwnik
	}

	int SafeRespond();

};

