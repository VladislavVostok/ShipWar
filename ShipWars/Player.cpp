#include "Player.hpp"
#include "Board.cpp"
#include <string>

using namespace std;

Player::Player(string& name, Board& board) : name(name), board(board) {}

inline void Player::placeShip(bool manual) {
	if (manual) {
		// Ручное размещение кораблей
		for (int size : SHIP_SIZES) {
			board.display(true);
			int x, y;
			bool horizontal;
			cout << name << ", размещает корабль размера " << size << " x y horizontal(0/1): ";
			cin >> x >> y >> horizontal;

			while (!board.isValidPlacement(x, y, size, horizontal)) {
				board.placeShip(x, y, size, horizontal);
			}
		}
	}
	else {
	// Автоматическое размещение
		for (int size : SHIP_SIZES) {
			int x, y;
			bool horizontal;

			do {
				x = rand() % SIZE;
				y = rand() % SIZE;
				horizontal = rand() % 2;
			}
			while (!board.isValidPlacement(x, y, size, horizontal));

			board.placeShip(x, y, size, horizontal);

		}
	}
}