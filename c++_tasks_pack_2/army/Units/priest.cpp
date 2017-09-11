#include "priest.h"

Priest::Priest() : MagicUnit(HP::LOW, ARMOR::WEAK, PRIEST_ATTACK, PRIEST_MAGIC_POWER)
{
    spellbook[SpellName::heal] = new Heal();
};

std::string Priest::getClass() const
{
    return this->className;
}

void Priest::attack(Unit *enemy)
{
    throw ArmyException("Priest can not attack");
}

void Priest::counterAttack(Unit *enemy) {}

const std::string Priest::className = "Priest";