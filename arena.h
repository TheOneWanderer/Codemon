#ifndef ARENA_H
#define ARENA_H

#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAP_SIZE = 5;

class Arena {
private:
    char terrainMap[MAP_SIZE][MAP_SIZE];
    char visibleMap[MAP_SIZE][MAP_SIZE];
    void initializeTerrain();
    bool isValidNeighbor(int x, int y, char terrain);

public:
    Arena();
    void printVisibleMap(int playerX, int playerY) const;
    void revealTile(int x, int y);
    char getTerrainAt(int x, int y) const;
    bool isValidMove(int x, int y) const;
};

#endif // ARENA_H