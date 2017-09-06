#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <iostream>
#include <string>
#include "creatureextrastats.h"

class Vampire : public CreatureExtraStats
{
    public:
        Vampire(std::string argName);

        enum ExtraStats
        {
            LifestealAmount = CreatureExtraStats::StatsCount
        };

        static const int ExtraStatsCount = 1;
        static const char* ExtraStatsStrings[ExtraStatsCount];

        virtual void Attack(Creature& target) override;

        virtual int MagicDamageReceivedMultiplier() override {return 2;}

        virtual const std::string getClassName() const override {return "Vampire";}
};

std::ostream& operator<<(std::ostream&, Vampire&);

#endif // VAMPIRE_H
