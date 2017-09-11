#include "mage.h"

Mage::Mage() : MagicUnit(HP::LOW, ARMOR::WEAK, MAGE_ATTACK, MAGE_MAGIC_POWER) {};

const std::string &Mage::getClassName() const
{
    return this->className;
}

const std::string Mage::className = "Mage";