#include "game.h"
#include <iostream>

Game::Game() {
    initializeGame();
}

void Game::initializeGame() {
    // initialize player and computer contestants
    std::cout << "Initializing game..." << std::endl;
    player.prepare();
    computer.prepare();

}

void Game::playerTurn() {
    // print visible map and prompt player for actions
    std::cout << "Player's turn..." << std::endl;
    arena.printVisibleMap(2, 2); // example position
    // implement movement, scouting, and battle logic
}

void Game::computerTurn() {
    std::cout << "Computer's turn..." << std::endl;
    // implement AI logic for the computer's turn
}

bool Game::isGameOver() const {
    // check if one contestant has no Codémons left
    return player.getNumCodemons() == 0 || computer.getNumCodemons() == 0;
}

void Game::run() {
    while (!isGameOver()) {
        playerTurn();
        if (isGameOver()) break;
        computerTurn();
    }

    if (player.getNumCodemons() > 0) {
        std::cout << "Player wins!" << std::endl;
    } else {
        std::cout << "Computer wins!" << std::endl;
    }
}