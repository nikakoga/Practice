#include "Game.h"

Game::Game(Dealer& _dealer, HumanPlayer& _human, ComputerPlayer& _computer, Player* _startPlayer)
	: dealer(_dealer), human(_human), computer(_computer)
{
	dealer.startPlayer = _startPlayer;
	dealer.currentPlayer = _startPlayer;
	dealer.SetOtherPlayer();
}


void Game::Play()
{
	while (!GameOver())
	{
		while (!human.lostRound || !computer.lostRound) //dopoki komputer lub czlowiek nie przegra
		{
			std::cout << dealer.startPlayer->name << " starts" << "\n";
			dealer.PayStartFee();
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
		dealer.StartPlayerSwitch();
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


