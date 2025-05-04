#ifndef GAME_H
#define GAME_H

#include "arena.h"
#include "contestant.h"
#include "battle.h"

class Game {
private:
    Arena arena;
    Contestant player;
    Contestant computer;

    void initializeGame();
    void playerTurn();
    void computerTurn();
    bool isGameOver() const;

public:
    Game();
    void run();
};

#endif // GAME_H