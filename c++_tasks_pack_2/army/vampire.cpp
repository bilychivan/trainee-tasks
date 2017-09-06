#include "vampire.h"
#include "colors.h"

const char* Vampire::ExtraStatsStrings[Vampire::ExtraStatsCount]
{
    "Lifesteal amount"
};

Vampire::Vampire(std::string argName) : CreatureExtraStats(argName, ExtraStatsCount, ExtraStatsStrings)
{
    setStat(Creature::Stats::DamageType, DamageType::Melee);
    setStat(Creature::Stats::ArmorType, ArmorType::Cloth);
    setStat(Vampire::ExtraStats::LifestealAmount, 0.2);
}

void Vampire::Attack(Creature& target)
{
    Creature::Attack(target, 1);

    float lifestealAmount = getStat(Creature::Stats::Attack) * Vampire::getStat(Vampire::ExtraStats::LifestealAmount);

    std::cout << BOLD(FGRN(<< getName() <<)) << " stole " << FGRN(<< lifestealAmount <<) " "
              << Creature::StatsStrings[static_cast<int>(Creature::Stats::Health)] << " points from " << BOLD(FGRN(<< target.getName() <<)) << std::endl;

    setStat(Creature::Stats::Health, getStat(Creature::Stats::Health) + lifestealAmount);
}

std::ostream& operator<<(std::ostream& stream, Vampire& object)
{
    stream << (Creature&)object;

    stream << ", " << Vampire::ExtraStatsStrings[0] << ": " << object.getStat(Vampire::ExtraStats::LifestealAmount);

    return stream;
}