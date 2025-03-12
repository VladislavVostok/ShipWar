#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Board.hpp"
#include <vector>

using namespace std;

enum ComputerMode { RAMDOM, SMART };

class Player {
public:
    Player(const std::string& name, Board& board);
    void placeShip(bool manual);
    bool takeTurn(Board& opponetnBoard, ComputerMode mode);

private:
    std::string name;
    Board& board;
};

#endif // PLAYER_HPP