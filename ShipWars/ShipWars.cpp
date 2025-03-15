#include <iostream>
#include <vector>
#include "Board.hpp"
#include "Player.hpp"
#include "Game.hpp"


using namespace std;

const int NUM_SHIP = 10;	// Количество кораблей

// Структура для представления координат на поле.
struct Point {
	int x, y;
};


int main()
{	
	setlocale(LC_ALL, "");
	GameMode mode;
	ComputerMode computerMode;
	int choice;
	string Human = "Human";
	string ChatGPT = "ChatGPT";
	string DeepSeek = "DeepSeek";

	Player* p1 = nullptr;
	Player* p2 = nullptr;

	Board b1 = Board();
	Board b2 = Board();

	cout << "Выберите режим игры (1 - Human vs Computer, 2 - Computer vs Computer): ";
	cin >> choice;

	mode = (choice == 1) ? HUMAN_VS_COMPUTER : COMPUTER_VS_COMPUTER;

	if (mode == HUMAN_VS_COMPUTER) {
		cout << "Выберите режим игры компьютера (1 - Random, 2 - Smart): ";
		cin >> choice;

		p1 = new Player(Human, b1, HUMAN);
		p2 = new Player(DeepSeek, b2, COMPUTER);

		computerMode = (choice == 1) ? RAMDOM : SMART;
	}
	else {
		computerMode = SMART;
		p1 = new Player(ChatGPT, b1, COMPUTER);
		p2 = new Player(DeepSeek, b2, COMPUTER);
	}



	Game game = Game(mode, computerMode, p1, p2);
	game.setup();
	game.play();

	return 0;

}
