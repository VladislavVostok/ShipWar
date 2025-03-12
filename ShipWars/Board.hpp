/*
* 
Это механизм защиты от повторного включения (include guard) в C++. 
Он предотвращает множественное включение одного и того же заголовочного файла в проект, что может привести к ошибкам компиляции.

#ifndef BOARD_HPP — проверяет, не был ли уже определён макрос BOARD_HPP. 
                    Если не был, то код между #ifndef и #endif будет включён в компиляцию.

#define BOARD_HPP — определяет макрос BOARD_HPP, чтобы при повторном включении этого файла код между #ifndef и #endif был проигнорирован.

#endif — завершает блок защиты.

*/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

enum CellState { EMPTY, SHIP, HIT, MISS };

const int SIZE = 10;
const int SHIP_SIZES[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 }; // Размеры кораблей и их количество

/*
    Правила использования const в методах
    Ключевое слово const в конце объявления метода указывает, что этот метод не изменяет состояние объекта. 
    Такие методы называются константными методами.

    1. Константный метод не может изменять поля класса.
        Внутри метода isValidPlacement вы не можете изменять grid или другие поля класса Board.

        void Board::markHit(int x, int y) const {
        grid[x][y] = HIT; // Ошибка: попытка изменить поле в константном методе
}

    2. Константный метод может вызывать только другие константные методы.
        Например, если у вас есть метод isHit, он также должен быть объявлен как const, чтобы его можно было вызвать внутри isValidPlacement.

    3. Константный метод может быть вызван у константного объекта.
        Если объект класса объявлен как const, вы можете вызывать только константные методы.\

        const Board board;
        bool isValid = board.isValidPlacement(0, 0, 3, true); // OK
        board.placeShip(0, 0, 3, true); // Ошибка: placeShip не является константным методом

    4. Константный метод может быть перегружен неконстантной версией.

        bool Board::isValidPlacement(int x, int y, int size, bool horizontal) const;
        bool Board::isValidPlacement(int x, int y, int size, bool horizontal);

        Компилятор выберет подходящую версию в зависимости от того, вызван метод у константного или неконстантного объекта.

*/


class Board {
public:
    Board();
    void placeShip(int x, int y, int size, bool horizontal);
    bool isValidPlacement(int x, int y, int size, bool horizontal) const;
    bool isHit(int x, int y) const;
    bool isMiss(int x, int y) const;
    void markHit(int x, int y);
    void markMiss(int x, int y);
    void display(bool showShips) const;
    bool allShipSunk() const;

private:
    std::vector<std::vector<CellState>> grid;
};

#endif // BOARD_HPP