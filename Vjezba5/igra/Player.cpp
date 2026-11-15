#include <iostream>
#include "Player.h"

// definicije konstruktora i metode print

Player::Player(const std::string &name,Level l) : name(name),level(l) {}
void Player::print() const
{
    std::cout << "Igrac: " << name << '\n';
    std::cout << "Level: neprijatelja " << level.enemy_count()
              << ", oruzja " << level.weapon_count() << '\n';
}
