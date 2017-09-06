#ifndef MAGE_H
#define MAGE_H

#include <iostream>
#include <string>
#include "creature.h"

class Mage : public Creature
{
    public:
        Mage(std::string argName);

        virtual const std::string getClassName() const override {return "Mage";}
};

std::ostream& operator<<(std::ostream&, Mage&);

#endif // MAGE_H
