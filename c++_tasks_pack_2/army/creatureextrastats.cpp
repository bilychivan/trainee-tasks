#include "creatureextrastats.h"

CreatureExtraStats::CreatureExtraStats(std::string argName, int argExtraStatsCount, const char** argExtraStatsStrings) : Creature(argName)
{
    stats.reserve(stats.size() + argExtraStatsCount);
    for (int i = 0; i < argExtraStatsCount; i++)
    {
        Stat tmp;

        tmp.value = 0;
        tmp.name = argExtraStatsStrings[i];

        stats.push_back(tmp);
    }
}

const float CreatureExtraStats::getStat(unsigned int statNo) const
{
    return stats[statNo].value;
}

void CreatureExtraStats::setStat(unsigned int statNo, float value)
{
    if (statNo >= Creature::StatsCount)
    {
        stats[statNo].value = value;
    }
    else
    {
        throw CreatureException("ExtraStats::setStat can't handle base stats");
    }
}