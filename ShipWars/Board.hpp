/*
* 
��� �������� ������ �� ���������� ��������� (include guard) � C++. 
�� ������������� ������������� ��������� ������ � ���� �� ������������� ����� � ������, ��� ����� �������� � ������� ����������.

#ifndef BOARD_HPP � ���������, �� ��� �� ��� �������� ������ BOARD_HPP. 
                    ���� �� ���, �� ��� ����� #ifndef � #endif ����� ������� � ����������.

#define BOARD_HPP � ���������� ������ BOARD_HPP, ����� ��� ��������� ��������� ����� ����� ��� ����� #ifndef � #endif ��� ��������������.

#endif � ��������� ���� ������.

*/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

enum CellState { EMPTY, SHIP, HIT, MISS };

const int SIZE = 10;
const int SHIP_SIZES[] = { 4, 3, 3, 2, 2, 2, 1, 1, 1, 1 }; // ������� �������� � �� ����������

/*
    ������� ������������� const � �������
    �������� ����� const � ����� ���������� ������ ���������, ��� ���� ����� �� �������� ��������� �������. 
    ����� ������ ���������� ������������ ��������.

    1. ����������� ����� �� ����� �������� ���� ������.
        ������ ������ isValidPlacement �� �� ������ �������� grid ��� ������ ���� ������ Board.

        void Board::markHit(int x, int y) const {
        grid[x][y] = HIT; // ������: ������� �������� ���� � ����������� ������
}

    2. ����������� ����� ����� �������� ������ ������ ����������� ������.
        ��������, ���� � ��� ���� ����� isHit, �� ����� ������ ���� �������� ��� const, ����� ��� ����� ���� ������� ������ isValidPlacement.

    3. ����������� ����� ����� ���� ������ � ������������ �������.
        ���� ������ ������ �������� ��� const, �� ������ �������� ������ ����������� ������.\

        const Board board;
        bool isValid = board.isValidPlacement(0, 0, 3, true); // OK
        board.placeShip(0, 0, 3, true); // ������: placeShip �� �������� ����������� �������

    4. ����������� ����� ����� ���� ���������� ������������� �������.

        bool Board::isValidPlacement(int x, int y, int size, bool horizontal) const;
        bool Board::isValidPlacement(int x, int y, int size, bool horizontal);

        ���������� ������� ���������� ������ � ����������� �� ����, ������ ����� � ������������ ��� �������������� �������.

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