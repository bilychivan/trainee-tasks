#include "archer.h"

Archer::Archer() : Unit(HP::LOW, ARMOR::WEAK, ARCHER_ATTACK)
{
    resistanceToCounter = true;
};


const std::string &Archer::getClassName() const
{
    return this->className;
}

const std::string Archer::className = "Archer";