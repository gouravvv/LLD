// GameBoard.cpp
#include "GameBoard.h"

GameBoard::GameBoard() {
    snakes = {16, 47, 49, 56, 62, 64, 87, 93, 95, 98};
    ladders = {1, 4, 9, 21, 28, 36, 51, 71, 80};
}

int GameBoard::getNextPosition(int currentPosition, int diceRoll) {
    int newPosition = currentPosition + diceRoll;

    for (int ladder : ladders) {
        if (newPosition == ladder) {
            return newPosition + 10;
        }
    }

    for (int snake : snakes) {
        if (newPosition == snake) {
            return newPosition - 10;
        }
    }

    return newPosition;
}
