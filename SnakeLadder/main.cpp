// main.cpp
#include "Game.h"

int main() {
    std::vector<std::string> playerNames = {"Player 1", "Player 2"};
    Game game(playerNames);
    game.play();

    return 0;
}
