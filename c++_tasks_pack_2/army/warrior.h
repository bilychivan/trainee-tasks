#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <string>
#include "creature.h"

class Warrior : public Creature
{
    public:
        static constexpr float CriticalHitChance = 0.3;

        Warrior(std::string argName);

        virtual void Attack(Creature& target) override;

        virtual const std::string getClassName() const override {return "Warrior";}
};

std::ostream& operator<<(std::ostream&, Warrior&);

#endif // WARRIOR_H
