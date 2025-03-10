#include <iostream>
#include <vector>
#include "Board.hpp"
#include "Player.hpp"

using namespace std;

const int NUM_SHIP = 10;	// Количество кораблей


enum GameMode { HUMAN_VS_COMPUTER, COMPUTER_VS_COMPUTER };
enum ComputerMode { RAMDOM, INTELLIGENT };

// Структура для представления координат на поле.
struct Point {
	int x, y;
};



int main()
{

	string vasya = "Vasya";
	Board b = Board();
	Player p = Player(vasya, b);

	bool f = false;
	bool t = true;
	p.placeShip(f);
	b.display(t);

}
