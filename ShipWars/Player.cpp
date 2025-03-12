#include "Player.hpp"
#include <iostream>
#include <cstdlib> // Для rand()
#include <ctime>   // Для time()

Player::Player(const std::string& name, Board& board) : name(name), board(board) {}

void Player::placeShip(bool manual) {
    if (manual) {
        // Ручное размещение кораблей
        for (int size : SHIP_SIZES) {
            board.display(true);
            int x, y;
            bool horizontal;
            std::cout << name << ", размещает корабль размера " << size << " x y horizontal(0/1): ";
            std::cin >> x >> y >> horizontal;

            while (!board.isValidPlacement(x, y, size, horizontal)) {
                std::cout << "Некорректное размещение. Попробуйте снова: ";
                std::cin >> x >> y >> horizontal;
            }
            board.placeShip(x, y, size, horizontal);
        }
    }
    else {
        // Автоматическое размещение
        std::srand(std::time(0)); // Инициализация генератора случайных чисел
        for (int size : SHIP_SIZES) {
            int x, y;
            bool horizontal;

            do {
                x = std::rand() % SIZE;
                y = std::rand() % SIZE;
                horizontal = std::rand() % 2;
            } while (!board.isValidPlacement(x, y, size, horizontal));

            board.placeShip(x, y, size, horizontal);
        }
    }
}