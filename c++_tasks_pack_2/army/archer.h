#ifndef ARCHER_H
#define ARCHER_H

#include <iostream>
#include <string>
#include "creature.h"

class Archer : public Creature
{
    public:
        Archer(std::string argName);

        virtual bool CanBeCounterattacked() override {return false;}

        virtual const std::string getClassName() const override {return "Archer";}
    private:
};

std::ostream& operator<<(std::ostream&, Archer&);

#endif // ARCHER_H
