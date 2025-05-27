#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy {
public:
    Enemy(const std::string& name, int health, int attack);
    void takeDamage(int damage);
    int getHealth() const;
    std::string getName() const;
    int getAttack() const;

private:
    std::string name;
    int health;
    int attack;
};

#endif