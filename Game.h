#ifndef GAME_H
#define GAME_H

#include <string>
#include "Inventory.h"
#include "Enemy.h"

class Game {
public:
    Game();  // Default constructor
    void start();
private:
    void displayIntro();
    void choosePath();
    void encounterMonster();
    void findTreasure();
    void exploreRoom();
    Inventory inventory;
    Enemy enemy; // Ensure this is properly initialized
};

#endif