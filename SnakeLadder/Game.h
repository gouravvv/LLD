// Game.h
#pragma once
#include <vector>
#include "Player.h"
#include "GameBoard.h"

class Game {
public:
    std::vector<Player> players;
    GameBoard board;

    Game(std::vector<std::string> playerNames);
    void play();
};
