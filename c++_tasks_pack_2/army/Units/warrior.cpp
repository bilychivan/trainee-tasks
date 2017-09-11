#include "warrior.h"
#include <ctime>

Warrior::Warrior() : Unit(HP::HIGH, ARMOR::STRONG, WARRIOR_ATTACK)
{
    chanceToCrit = true;
    std::srand(std::time(0));
};

std::string Warrior::getClass() const
{
    return this->className;
}

const std::string Warrior::className = "Warrior";