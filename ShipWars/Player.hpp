#pragma once
#include <string>
#include "Board.hpp"

using namespace std;

class Player {

public:
	Player(string& name, Board& board);
	void placeShip(bool manual);

private: 
	string name;
	Board board;
};