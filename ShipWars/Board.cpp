#include "Board.hpp"
#include <iostream>

using namespace std;


const int SIZE = 10;
const int SHIP_SIZES[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 };	// размеры кораблей и их количество

inline Board::Board() {
	grid.resize(SIZE, vector<CellState>(SIZE, EMPTY));
}


void Board::placeShip(int x, int y, int size, bool horizontal) {
	for (int i = 0; i < size; ++i) {
		if (horizontal) {
			grid[x][y + i] = SHIP; // Горизонтальное размещение
		}
		else {
			grid[x + i][y] = SHIP;
		}
	}
}


inline bool Board::isValidPlacement(int x, int y, int size, bool horizontal) {
	for (int i = 0; i < size; ++i) {
		int nx = x + (horizontal ? 0 : i);
		int ny = y + (horizontal ? i : 0);

		// TODO: Добавить проверку что корабль от другого корабля долже находить дальше одной клетки.

		if (nx >= SIZE || ny >= SIZE || grid[nx][ny] != EMPTY) {
			return false;
		}
	}
	return true;
}


inline bool Board::isHit(int x, int y) {
	return grid[x][y] == SHIP;
}

inline bool Board::isMiss(int x, int y) {
	return grid[x][y] == MISS;
}

inline void Board::markHit(int x, int y) {
	grid[x][y] = HIT;
}

inline void Board::markMiss(int x, int y) {
	grid[x][y] = MISS;
}

inline void Board::display(bool showShips) {
	// Гозиротальная шака поля
	cout << " ";
	for (int i = 0; i < SIZE; ++i) {
		cout << i << " ";
	}
	cout << endl;

	// Cтолбцы.
	for (int i = 0; i < SIZE; ++i) {
		cout << i << " ";
		for (int j = 0; j < SIZE; ++j) {
			if (grid[i][j] == HIT) cout << "X ";
			else if (grid[i][j] == MISS) cout << "O ";
			else if (showShips && grid[i][j] == SHIP) cout << "S ";
			else cout << "* ";
		}
		cout << endl;
	}
	cout << endl;
}


inline bool Board::allShipSunk() {
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (grid[i][j] == SHIP) return false;
		}
	}
	return true;
}


