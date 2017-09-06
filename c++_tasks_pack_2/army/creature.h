#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <string>
#include <vector>

class Creature
{
    public:
        Creature(std::string argName);

        struct Stat
        {
            float value;
            const char* name;
        };

        enum class Stats
        {
            Health,
            MaxHealth,
            Attack,
            Armor,
            Intellegence,
            DamageType,
            ArmorType
        };

        enum class DamageType
        {
            Melee,
            Ranged,
            Magic
        };

        enum class ArmorType
        {
            Cloth,
            Leather,
            Plate,
            Unarmored
        };

        static const char* StatUndefined;

        static const unsigned int StatsCount = 7;

        static const char *StatsStrings[StatsCount];

        static const bool StatDisplayByValue[StatsCount];

        static const unsigned int DamageTypeCount = 3;
        static const char *DamageTypeStrings[DamageTypeCount];

        static const unsigned int ArmorTypeCount = 4;
        static const char *ArmorTypeStrings[ArmorTypeCount];
        static const float ArmorTypeMultiplier[ArmorTypeCount];

        static constexpr float ChanceToCounterattack = 0.5;

        static constexpr float CounterattackDamageDivider = 2;

        const std::vector<Stat>& getStats() const;

        void setStat(Stats statNo, float value);
        void setStat(Stats statNo, DamageType value);
        void setStat(Stats statNo, ArmorType value);

        virtual const float getStat(Stats statNo) const;

        const std::string& getName() const;

        const DamageType getDamageType() const;

        const bool isAlive() const;

        const bool isCorpse() const;

        void setCorpse(bool status);

        virtual bool Attack(Creature& target, float damageMultiplier);
        virtual bool Attack(Creature& target);

        virtual void ReceiveDamage(DamageType type, float amount, Creature& attacker, bool canCounter);

        virtual bool Counterattack(Creature& target);

        virtual bool CanBeCounterattacked() {return true;}

        virtual int MagicDamageReceivedMultiplier() {return 1;}

        virtual const std::string getClassName() const {return "Creature";}

    protected:
        std::vector<Stat> stats;

    private:
        std::string name;

        bool alive;
        bool corpse;
};

std::ostream& operator<<(std::ostream&, Creature&);

class CreatureException : public std::logic_error
{
    public:
        CreatureException(const char*);
};

#endif // CREATURE_H
