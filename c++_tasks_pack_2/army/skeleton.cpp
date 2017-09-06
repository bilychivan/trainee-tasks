#include "skeleton.h"

Skeleton::Skeleton(std::string argName) : Creature(argName)
{
    setStat(Creature::Stats::DamageType, DamageType::Melee);
    setStat(Creature::Stats::ArmorType, ArmorType::Unarmored);
}

std::ostream& operator<<(std::ostream& stream, Skeleton& object)
{
    stream << (Creature&)object;

    return stream;
}