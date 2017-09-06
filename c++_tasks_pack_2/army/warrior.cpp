#include <stdlib.h>
#include "warrior.h"

Warrior::Warrior(std::string argName) : Creature(argName)
{
    setStat(Creature::Stats::DamageType, DamageType::Melee);
    setStat(Creature::Stats::ArmorType, ArmorType::Plate);
}

bool Warrior::Attack(Creature& target)
{
    float crit = static_cast<float>((rand() % 100) / 100.);

    if (crit < CriticalHitChance)
    {
        Creature::Attack(target, 2);
    }
    else
    {
        Creature::Attack(target, 1);
    }

    return true;
}

std::ostream& operator<<(std::ostream& stream, Warrior& object)
{
    stream << (Creature&)object;

    return stream;
}