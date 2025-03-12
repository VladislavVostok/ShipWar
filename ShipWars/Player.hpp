#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Board.hpp"

class Player {
public:
    Player(const std::string& name, Board& board);
    void placeShip(bool manual);

private:
    std::string name;
    Board& board;
};

#endif // PLAYER_HPP