#include "archer.h"

Archer::Archer(std::string argName) : Creature(argName)
{
    setStat(Creature::Stats::DamageType, DamageType::Ranged);
    setStat(Creature::Stats::ArmorType, ArmorType::Leather);
}

std::ostream& operator<<(std::ostream& stream, Archer& object)
{
    stream << (Creature&)object;

    return stream;
}