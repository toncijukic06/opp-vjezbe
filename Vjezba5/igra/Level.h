#pragma once // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <vector>
#include "Enemy.h"
#include "Weapon.h"

class Level
{
    // data memberi

    std::vector<Enemy> enemies;
    std::vector<Weapon> weapons;

public:
    // konstruktor
    Level();
    int enemy_count() const;
    int weapon_count() const;
};
