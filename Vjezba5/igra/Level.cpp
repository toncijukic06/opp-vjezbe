#include "Level.h"

// definicije konstruktora i metoda
Level::Level() : enemies{Enemy(100)}
{
}

int Level::enemy_count() const
{
    return enemies.size();
}

int Level::weapon_count() const
{
    return weapons.size();
}