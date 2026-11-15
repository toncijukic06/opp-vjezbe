#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <string>
#include "Level.h"

class Player {
    std::string name;
    Level level;


public:
    // konstruktor
    Player(const std::string& name, Level l);
    void print() const;      // ime i stanje levela u kojem je igrac
};
