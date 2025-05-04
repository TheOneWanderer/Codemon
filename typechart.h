#ifndef TYPECHART_H
#define TYPECHART_H

#include <string>
#include <unordered_map>

class TypeChart {
private:
    static constexpr float chart[4][4] = {
        {1.0, 0.5, 2.0, 1.0}, // Fire
        {2.0, 1.0, 0.5, 1.0}, // Water
        {0.5, 2.0, 1.0, 1.0}, // Grass
        {1.0, 2.0, 1.0, 1.0}  // Electric
    };
    std::unordered_map<std::string, int> typeIndex = {
        {"Fire", 0},
        {"Water", 1},
        {"Grass", 2},
        {"Electric", 3}
    };

public:
    float getMultiplier(const std::string& attacker, const std::string& defender) const;
};

#endif // TYPECHART_H