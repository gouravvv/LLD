// GameBoard.h
#pragma once
#include <vector>

class GameBoard {
public:
    std::vector<int> snakes;
    std::vector<int> ladders;

    GameBoard();
    int getNextPosition(int currentPosition, int diceRoll);
};
