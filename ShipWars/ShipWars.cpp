#include <iostream>
#include <vector>
#include "Board.hpp"
#include "Player.hpp"


using namespace std;

const int NUM_SHIP = 10;	// Количество кораблей

// Структура для представления координат на поле.
struct Point {
	int x, y;
};


int main()
{
	cout << SIZE;

	string vasya = "Vasya";
	string vasya2 = "Vasya2";
	Board b1 = Board();
	Board b2 = Board();
	Player p1 = Player(vasya, b1, COMPUTER);
	Player p2 = Player(vasya2, b2, COMPUTER);

	bool f = false;
	bool t = true;


}
