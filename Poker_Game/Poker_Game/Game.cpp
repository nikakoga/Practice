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
		human.lostRound = false;
		computer.lostRound = false;

		while (!human.lostRound && !computer.lostRound) //dopoki komputer lub czlowiek nie przegra
		{
			std::cout << dealer.startPlayer->name << " starts" << "\n";
			dealer.PayStartFee();
			Auctions();
			Sleep();
			dealer.SetTable();
			Auctions();
			Sleep();
			dealer.GiveCard();
			Auctions();
			Sleep();
			dealer.GiveCard();
			Auctions();
			//ocena kombinacji
			//porownanie
			//kasa do wygranego
			std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << "\n" << "\n";
			break; //dzieki temu wykona sie tylko raz na runde
		}
		//if (human.lostRound)

		dealer.Clean();
		dealer.StartPlayerSwitch();
	}
}

void Game::Auctions()
{
	if (!human.lostRound && !computer.lostRound) //jesli ktos zdazyl przegrac to nastepne akcje w funkcji Play nie beda nic robic
	{
		dealer.currentPlayer = dealer.startPlayer;
		dealer.SetOtherPlayer();
		human.finished = false;
		computer.finished = false;

		while (!human.finished || !computer.finished)
		{
			dealer.OptionMatchOrFold();
			if (human.lostRound || computer.lostRound)
			{
				break; // jesli ktos spasuje na tym etapie to nie pytam go potem czy jednak podbija
			}
			dealer.OptionRaise();
			if (human.finished && computer.finished)
			{
				break; //jesli nastapil check to nie ma po co zmieniac gracza
			}
			dealer.NextPlayer();
		}
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

void Game::Sleep()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}


