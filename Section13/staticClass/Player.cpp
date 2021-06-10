#include "Player.h"

int Player::count {0};

std::string Player::getName() {
    return name;
}

int Player::gethealth() {
    return health;
}

int Player::getXp() {
    return xp;
}

int Player::getPlayerCount() {
    return count;
}

Player::Player(std::string nameVal, int healthVal, int xpVal)
    : name {nameVal}, health {healthVal}, xp {xpVal} {
    ++count;
}

Player::Player(const Player &src) 
    : Player {src.name, src.health, src.xp} {
}

Player::~Player() {
    --count;
}