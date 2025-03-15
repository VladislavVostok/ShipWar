#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Board.hpp"
#include <vector>

using namespace std;

enum ComputerMode { RAMDOM, SMART };
enum TypePlayer { HUMAN, COMPUTER };


class Player {
public:
    Player(std::string& name, Board& board, TypePlayer typePlayer);
    void placeShip(bool manual);
    bool takeTurn(Board& opponetnBoard, ComputerMode mode);
    bool hasLost() const;
    void displayBoard(bool showShips) const;
    Board& getBoard();
    TypePlayer getTypePlaeyr() const;

private:
    std::string name;
    Board& board;
    TypePlayer typePlayer;
};

#endif // PLAYER_HPP