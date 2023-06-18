#include "Game.h"

Game::Game(Dealer& _dealer, HumanPlayer& _human, ComputerPlayer& _computer, Player* _startPlayer)
	: dealer(_dealer), human(_human), computer(_computer)
{
	startPlayer = _startPlayer;
	dealer.startPlayer = _startPlayer;
	dealer.currentPlayer = _startPlayer;
	
	if (startPlayer == &human){
		dealer.otherPlayer = &computer;
	}
	else
	{
		dealer.otherPlayer = &human;
	}
}

void Game::PayStartFee()
{
	human.PayUp(startPay,"start");
	computer.PayUp(startPay,"start");
}

void Game::Play()
{
	while (!GameOver())
	{
		while (!human.lostRound || !computer.lostRound) //dopoki komputer lub czlowiek nie przegra
		{
			std::cout << startPlayer->name << " starts" << "\n";
			PayStartFee();
			Auctions();
			dealer.SetTable();
			Auctions();
			dealer.GiveCard();
			Auctions();
			dealer.GiveCard();
			Auctions();
			//ocena kombinacji
			//porownanie
			//kasa do wygranego
			std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << "\n" << "\n";
			break; //dzieki temu wykona sie tylko raz lub nawet mniej jesli ktos przegra wczesniej
		}
		//if (human.lostRound)

		dealer.Clean();
		StartPlayerSwitch();
	}
}

void Game::Auctions()
{
	human.finished = false;
	computer.finished = false;
	while (!human.finished || !computer.finished)
	{
		dealer.OptionMatchOrFold();
		dealer.OptionRaise();
		dealer.NextPlayer();
	}
}

bool Game::GameOver()
{
	if (human.bankrupt || computer.bankrupt)
	{
		return true;
	}
	return false;
}

void Game::StartPlayerSwitch()
{
	if (startPlayer == &human)
	{
		startPlayer = &computer;
	}
	else
	{
		startPlayer = &human;
	}
}

