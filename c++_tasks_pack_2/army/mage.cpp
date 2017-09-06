#include "mage.h"

Mage::Mage(std::string argName) : Creature(argName)
{
    setStat(Creature::Stats::DamageType, DamageType::Magic);
    setStat(Creature::Stats::ArmorType, ArmorType::Cloth);
}

std::ostream& operator<<(std::ostream& stream, Mage& object)
{
    stream << (Creature&)object;

    return stream;
}