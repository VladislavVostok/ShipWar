#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include "Player.hpp"


using namespace std;


enum GameMode { HUMAN_VS_COMPUTER, COMPUTER_VS_COMPUTER };

class Game {
public:
    Game(GameMode mode, ComputerMode computerMode, Player* player1, Player* player2);
    void setup();
    void play();

private:
    GameMode mode;
    ComputerMode computerMode;
    vector<Player*> players; // Список игроков
};

#endif // GAME_HPP