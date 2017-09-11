#include "mage.h"

Mage::Mage() : MagicUnit(HP::LOW, ARMOR::WEAK, MAGE_ATTACK, MAGE_MAGIC_POWER) {};

std::string Mage::getClass() const
{
    return this->className;
}

const std::string Mage::className = "Mage";