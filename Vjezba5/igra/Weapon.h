#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>

class Weapon {
    std::string name;
    int damage;

public:
    Weapon(const std::string& name, int damage);
};
