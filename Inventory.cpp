#include "Inventory.h"

Inventory::Inventory() : health(100) {}

void Inventory::addItem(const std::string& item) {
    items.push_back(item);
}

void Inventory::takeDamage(int damage) {
    health -= damage;
}

int Inventory::getHealth() const {
    return health;
}

void Inventory::displayItems() const {
    if (items.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
    }
    else {
        std::cout << "You have the following items in your inventory:" << std::endl;
        for (const auto& item : items) {
            std::cout << "- " << item << std::endl;
        }
    }
}