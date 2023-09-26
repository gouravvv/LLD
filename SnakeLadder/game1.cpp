#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the Player class
class Player {
public:
    string name;
    int position;

    Player(string playerName) {
        name = playerName;
        position = 0;
    }
};

// Define the GameBoard class
class GameBoard {
public:
    vector<int> snakes;   // Snakes' head positions
    vector<int> ladders;  // Ladders' start positions

    GameBoard() {
        // Initialize the board with snakes and ladders
        snakes = {16, 47, 49, 56, 62, 64, 87, 93, 95, 98};
        ladders = {1, 4, 9, 21, 28, 36, 51, 71, 80};
    }

    int getNextPosition(int currentPosition, int diceRoll) {
        int newPosition = currentPosition + diceRoll;
        
        // Check if the new position has a ladder
        for (int ladder : ladders) {
            if (newPosition == ladder) {
                cout << "Climbed a ladder! ";
                return newPosition + 10;  // Ladder climb adds 10 positions
            }
        }
        
        // Check if the new position has a snake
        for (int snake : snakes) {
            if (newPosition == snake) {
                cout << "Got bitten by a snake! ";
                return newPosition - 10;  // Snake bite deducts 10 positions
            }
        }
        
        return newPosition;
    }
};

// Define the Game class
class Game {
public:
    vector<Player> players;
    GameBoard board;

    Game(vector<string> playerNames) {
        for (string playerName : playerNames) {
            players.push_back(Player(playerName));
        }
    }

    void play() {
        srand(time(0));  // Initialize random seed
        int currentPlayerIndex = 0;

        while (true) {
            Player& currentPlayer = players[currentPlayerIndex];
            cout << currentPlayer.name << "'s turn. Press Enter to roll the dice...";
            cin.get();

            int diceRoll = (rand() % 6) + 1;
            cout << "You rolled a " << diceRoll << ". ";

            currentPlayer.position = board.getNextPosition(currentPlayer.position, diceRoll);
            cout << currentPlayer.name << " is now at position " << currentPlayer.position << endl;

            if (currentPlayer.position >= 100) {
                cout << currentPlayer.name << " wins!" << endl;
                break;
            }

            currentPlayerIndex = (currentPlayerIndex + 1) % players.size();
        }
    }
};

int main() {
    vector<string> playerNames = {"Player 1", "Player 2"};
    Game game(playerNames);
    game.play();

    return 0;
}

