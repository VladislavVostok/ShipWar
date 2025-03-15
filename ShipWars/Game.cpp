#include "Game.hpp"
#include <vector>

using namespace std;

Game::Game(GameMode mode, ComputerMode computerMode, Player player1, Player player2) {

	this->mode = mode;
	this->computerMode = computerMode;
	players.push_back(player1);
	players.push_back(player2);
}

void Game::setup() {
	if (players[0].getTypePlaeyr() == HUMAN) {
		players[0].placeShip(true);
		players[1].placeShip(false);
	}
	else {
		players[0].placeShip(false);
		players[1].placeShip(false);
	}
}

void Game::play() {

}



