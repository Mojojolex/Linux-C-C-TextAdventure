#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <iostream>

class Inventory {
public:
    Inventory();
    void addItem(const std::string& item);
    void takeDamage(int damage);
    int getHealth() const;
    void displayItems() const; // New method to display inventory

private:
    std::vector<std::string> items;
    int health;
};

#endif