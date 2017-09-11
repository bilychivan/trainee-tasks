#include "archer.h"

Archer::Archer() : Unit(HP::LOW, ARMOR::WEAK, ARCHER_ATTACK)
{
    resistanceToCounter = true;
};


std::string Archer::getClass() const
{
    return this->className;
}

const std::string Archer::className = "Archer";