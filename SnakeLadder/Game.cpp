// Game.cpp
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(std::vector<std::string> playerNames) {
    for (std::string playerName : playerNames) {
        players.push_back(Player(playerName));
    }
}

void Game::play() {
    srand(time(0));
    int currentPlayerIndex = 0;

    while (true) {
        Player& currentPlayer = players[currentPlayerIndex];
        std::cout << currentPlayer.name << "'s turn. Press Enter to roll the dice...";
        std::cin.get();

        int diceRoll = (rand() % 6) + 1;
        std::cout << "You rolled a " << diceRoll << ". ";

        currentPlayer.position = board.getNextPosition(currentPlayer.position, diceRoll);
        std::cout << currentPlayer.name << " is now at position " << currentPlayer.position << std::endl;

        if (currentPlayer.position >= 100) {
            std::cout << currentPlayer.name << " wins!" << std::endl;
            break;
        }

        currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
    }
}
