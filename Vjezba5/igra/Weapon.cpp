#include "Weapon.h"

// definicija konstruktora: Weapon::Weapon(...) : ... {}
Weapon::Weapon(const std::string& name, int damage)
    : name(name), damage(damage)
{
}