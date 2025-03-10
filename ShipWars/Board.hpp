#pragma once
#include <vector>

enum CellState { EMPTY, SHIP, HIT, MISS };

using namespace std;

class Board {
public:
	Board();
	void placeShip(int x, int y, int size, bool horizontal);
	bool isValidPlacement(int x, int y, int size, bool horizontal);
	bool isHit(int x, int y);
	bool isMiss(int x, int y);
	void markHit(int x, int y);
	void markMiss(int x, int y);
	void display(bool showShips);
	bool allShipSunk();

private:
	vector<vector<CellState>> grid;
};