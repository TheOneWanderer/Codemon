#include "typechart.h"

// defines the static member variable chart
constexpr float TypeChart::chart[4][4];

float TypeChart::getMultiplier(const std::string& attacker, const std::string& defender) const {
    int attackerIndex = typeIndex.at(attacker);
    int defenderIndex = typeIndex.at(defender);
    return chart[attackerIndex][defenderIndex];
}