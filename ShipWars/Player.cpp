#include "Player.hpp"
#include <iostream>
#include <cstdlib> // ��� rand()
#include <ctime>   // ��� time()

#if false
    #include <tuple>   // tie(x,y)
#endif
Player::Player(const std::string& name, Board& board) : name(name), board(board) {}

void Player::placeShip(bool manual) {
    if (manual) {
        // ������ ���������� ��������
        for (int size : SHIP_SIZES) {
            board.display(true);
            int x, y;
            bool horizontal;
            std::cout << name << ", ��������� ������� ������� " << size << " x y horizontal(0/1): ";
            std::cin >> x >> y >> horizontal;

            while (!board.isValidPlacement(x, y, size, horizontal)) {
                std::cout << "������������ ����������. ���������� �����: ";
                std::cin >> x >> y >> horizontal;
            }
            board.placeShip(x, y, size, horizontal);
        }
    }
    else {
        // �������������� ����������
        std::srand(std::time(0)); // ������������� ���������� ��������� �����
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




bool Player::takeTurn(Board& opponetnBoard, ComputerMode mode) {
    int x, y;
    static vector<pair<int, int>> targets;
    if (name == "Computer") {       // ��� ����������
        if (mode == SMART) {        // ����� Smart ��������
            if (!targets.empty()) {
                tie(x, y) = targets.back();
                targets.pop_back();
            }
            else {  
                do {
                    x = rand() % SIZE;
                    y = rand() % SIZE;
                } while (   opponetnBoard.isHit(x, y)
                            || opponetnBoard.isMiss(x, y)
                            || (x + y) % 2 != 0
                  );

            }
        }
        else {          // ����� ��������� ��������
            do {
                x = rand() % SIZE;
                y = rand() % SIZE;
            } while (opponetnBoard.isHit(x, y) || opponetnBoard.isMiss(x, y));

        }

    }
    else {    // ��� ��������
        cout << name << ", ������� ���������� ��� �������� (x y): ";
        cin >> x >> y;

        while (x < 0 || x >= SIZE || y < 0 || y >= SIZE || opponetnBoard.isHit(x, y) || opponetnBoard.isMiss(x, y)) {
            cout << "������������ ����������. ���������� ���: ";
            cin >> x >> y;
        }
    }

    if (opponetnBoard.isShip(x, y)) {
        cout << name << "����� �� (" << x << ", " << y << ")!" << endl;
        opponetnBoard.markHit(x, y);

        if (x > 0 && !opponetnBoard.isHit(x - 1, y) && !opponetnBoard.isMiss(x - 1, y))
            targets.emplace_back(x - 1, y);

        if (x < SIZE - 1 && !opponetnBoard.isHit(x +1, y) && !opponetnBoard.isMiss(x + 1, y))
            targets.emplace_back(x + 1, y);

        if (y > 0 && !opponetnBoard.isHit(x, y - 1) && !opponetnBoard.isMiss(x, y - 1))
            targets.emplace_back(x, y - 1);

        if (y < SIZE - 1 && !opponetnBoard.isHit(x, y + 1) && !opponetnBoard.isMiss(x, y + 1))
            targets.emplace_back(x, y + 1);

        return true; // �������� ���

    }
    else {
        cout << name << ", ����������� �� (" << x << ", " << y << ")" << endl;
        opponetnBoard.markMiss(x, y);
        return false;   // ��������� ���
    }


}