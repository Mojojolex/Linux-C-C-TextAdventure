#include "Game.h"
#include <iostream>

Game::Game() : enemy("", 0, 0) { // Initialize enemy with default values
    // Inventory is automatically initialized
}

void Game::start() {
    displayIntro();
    choosePath();
}

void Game::displayIntro() {
    std::cout << "Welcome to the Text Adventure Game!" << std::endl;
    std::cout << "You find yourself in a dark forest." << std::endl;
}

void Game::choosePath() {
    std::cout << "Do you want to go to the cave or the village? (c/v): ";
    char choice;
    std::cin >> choice;

    if (choice == 'c') {
        exploreRoom();
    }
    else if (choice == 'v') {
        findTreasure();
    }
    else {
        std::cout << "Invalid choice. Try again." << std::endl;
        choosePath();
    }
}

void Game::exploreRoom() {
    std::cout << "You enter a cave and encounter a monster!" << std::endl;
    enemy = Enemy("Goblin", 20, 5);
    encounterMonster();
}

void Game::encounterMonster() {
    std::cout << "A " << enemy.getName() << " appears!" << std::endl;

    while (enemy.getHealth() > 0) {
        std::cout << "Do you want to (a)ttack, (r)un, or (i)nventory? ";
        char action;
        std::cin >> action;

        if (action == 'a') {
            enemy.takeDamage(10);
            std::cout << "You dealt 10 damage to the " << enemy.getName() << "!" << std::endl;
            if (enemy.getHealth() <= 0) {
                std::cout << "You defeated the " << enemy.getName() << "!" << std::endl;
                inventory.addItem("Monster Tooth");
                std::cout << "You found a Monster Tooth!" << std::endl;
                break;
            }
            std::cout << "The " << enemy.getName() << " attacks you!" << std::endl;
            inventory.takeDamage(enemy.getAttack());
            std::cout << "You have " << inventory.getHealth() << " health left." << std::endl;
            if (inventory.getHealth() <= 0) {
                std::cout << "You have been defeated!" << std::endl;
                break;
            }
        }
        else if (action == 'r') {
            std::cout << "You ran away!" << std::endl;
            break;
        }
        else if (action == 'i') {
            inventory.displayItems(); // Check inventory
        }
        else {
            std::cout << "Invalid choice. Try again." << std::endl;
        }
    }
}

void Game::findTreasure() {
    std::cout << "Congratulations! You found the treasure!" << std::endl;
    inventory.addItem("Gold Coin");
    std::cout << "You found a Gold Coin!" << std::endl;
}