#ifndef BATTLE_H
#define BATTLE_H

#include "codemon.h"
#include "typechart.h"

class Battle {
private:
    Codemon& attacker;
    Codemon& defender;
    TypeChart typeChart;

    void resolveRound();

public:
    Battle(Codemon& attacker, Codemon& defender);

    void start();
};

#endif // BATTLE_H