#include "Game.hpp"
#include <vector>

using namespace std;

Game::Game(GameMode mode, ComputerMode computerMode, Player* player1, Player* player2) {

	this->mode = mode;
	this->computerMode = computerMode;
	players.push_back(player1);
	players.push_back(player2);
}

void Game::setup() {
	std::srand(std::time_t(0)); // Инициализация генератора случайных чисел

	if ((*players[0]).getTypePlaeyr() == HUMAN) {
		(*players[0]).placeShip(false);
		(*players[1]).placeShip(false);
	}
	else {
		(*players[0]).placeShip(false);
		(*players[1]).placeShip(false);
	}
}

void Game::play() {
	while (true) {
		for (int i = 0; i < players.size(); ++i) {
			cout << "Player " << i + 1 << " делает ход:" << endl;
			(*players[i]).displayBoard(true);
			(*players[(i + 1) % players.size()]).displayBoard(true);
		
			bool hit = (*players[i]).takeTurn((*players[(i + 1) % players.size()]).getBoard(), computerMode);

			if ((*players[(i + 1) % players.size()]).hasLost()) {
				cout << "Player " << i + 1 << "победил" << endl;
				return;
			}

			if (hit && mode == HUMAN_VS_COMPUTER && i == 1) {
				--i;
			}
		}
	}
}



