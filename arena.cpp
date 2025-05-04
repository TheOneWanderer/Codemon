#include "arena.h"

// constructor initializes terrain and visibility maps
Arena::Arena() {
    initializeTerrain();
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            visibleMap[i][j] = '#';  // All tiles hidden initially
        }
    }
}

// isnitialize the terrain map with unique neighboring tiles
void Arena::initializeTerrain() {
    srand(1025); // fixed seed for predictable results
    char terrainTypes[] = {'F', 'M', 'P', 'W', 'S'};
    
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            char terrain;
            do {
                terrain = terrainTypes[rand() % 5];
            } while (!isValidNeighbor(i, j, terrain));
            terrainMap[i][j] = terrain;
        }
    }
}

// checks if the  terrain is valid based on neighboring tiles
bool Arena::isValidNeighbor(int x, int y, char terrain) {
    if (x > 0 && terrainMap[x - 1][y] == terrain) return false;
    if (y > 0 && terrainMap[x][y - 1] == terrain) return false;
    return true;
}

// print visible map
void Arena::printVisibleMap(int playerX, int playerY) const {
    for (int i = 0; i < MAP_SIZE; ++i) {
        for (int j = 0; j < MAP_SIZE; ++j) {
            if (i == playerX && j == playerY) {
                std::cout << '@';  // Player's position
            } else {
                std::cout << visibleMap[i][j];
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

// reveals specific tile
void Arena::revealTile(int x, int y) {
    visibleMap[x][y] = terrainMap[x][y];
}

// get terrain at a specific location
char Arena::getTerrainAt(int x, int y) const {
    return terrainMap[x][y];
}

// check if a move is valid
bool Arena::isValidMove(int x, int y) const {
    return x >= 0 && x < MAP_SIZE && y >= 0 && y < MAP_SIZE;
}