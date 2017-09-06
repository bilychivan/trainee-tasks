#ifndef CREATUREEXTRASTATS_H
#define CREATUREEXTRASTATS_H

#include <iostream>
#include <string>
#include <vector>
#include "creature.h"

class CreatureExtraStats : public Creature
{
    public:
        CreatureExtraStats(std::string argName, int argExtraStatsCount, const char** argExtraStatsStrings);

        static const int ExtraStatsCount;
        static const char** ExtraStatsStrings;

        using Creature::setStat;
        void setStat(unsigned int statNo, float value);

        using Creature::getStat;
        virtual const float getStat(unsigned int statNo) const;

        virtual const std::string getClassName() const override {return "CreatureExtraStats";}
    private:
};

#endif // CREATUREEXTRASTATS_H
