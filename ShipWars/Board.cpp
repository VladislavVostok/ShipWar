#include "Board.hpp"

Board::Board() {
    grid.resize(SIZE, std::vector<CellState>(SIZE, EMPTY));
}

void Board::placeShip(int x, int y, int size, bool horizontal) {
    for (int i = 0; i < size; ++i) {
        if (horizontal) {
            grid[x][y + i] = SHIP; // Горизонтальное размещение
        }
        else {
            grid[x + i][y] = SHIP; // Вертикальное размещение
        }
    }
}

bool Board::isValidPlacement(int x, int y, int size, bool horizontal) const {
    for (int i = 0; i < size; ++i) {
        int nx = x + (horizontal ? 0 : i);
        int ny = y + (horizontal ? i : 0);

        // Проверка на выход за границы поля
        if (nx >= SIZE || ny >= SIZE || grid[nx][ny] != EMPTY) {
            return false;
        }

        // Проверка соседних клеток
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                int cx = nx + dx;
                int cy = ny + dy;
                if (cx >= 0 && cx < SIZE && cy >= 0 && cy < SIZE && grid[cx][cy] == SHIP) {
                    return false;
                }
            }
        }
    }
    return true;
}

bool Board::isHit(int x, int y) const {
    return grid[x][y] == SHIP;
}

bool Board::isMiss(int x, int y) const {
    return grid[x][y] == MISS;
}

void Board::markHit(int x, int y) {
    grid[x][y] = HIT;
}

void Board::markMiss(int x, int y) {
    grid[x][y] = MISS;
}

void Board::display(bool showShips) const {
    // Горизонтальная шапка поля
    std::cout << "  ";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Строки и столбцы
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == HIT) std::cout << "X ";
            else if (grid[i][j] == MISS) std::cout << "O ";
            else if (showShips && grid[i][j] == SHIP) std::cout << "S ";
            else std::cout << "~ "; // Используем "~" для обозначения воды
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Board::allShipSunk() const {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == SHIP) return false;
        }
    }
    return true;
}