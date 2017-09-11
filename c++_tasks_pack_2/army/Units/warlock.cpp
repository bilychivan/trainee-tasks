#include "warlock.h"

Warlock::Warlock() : MagicUnit(HP::LOW, ARMOR::WEAK, WARLOCK_ATTACK, WARLOCK_MAGIC_POWER)
{
    spellbook[SpellName::summonSkeleton] = new SummonSkeleton();
};

std::string Warlock::getClass() const
{
    return this->className;
}

const std::string Warlock::className = "Warlock";