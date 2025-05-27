#include "Enemy.h"

Enemy::Enemy(const std::string& name, int health, int attack)
    : name(name), health(health), attack(attack) {
}

void Enemy::takeDamage(int damage) {
    health -= damage;
}

int Enemy::getHealth() const {
    return health;
}

std::string Enemy::getName() const {
    return name;
}

int Enemy::getAttack() const {
    return attack;
}