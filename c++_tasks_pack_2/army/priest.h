#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>
#include <string>
#include "creatureextrastats.h"
#include "spellbook.h"

class Priest : public Creature
{
    public:
        Priest(std::string argName);

        virtual const std::string getClassName() const override {return "Priest";}

        Spellbook spellbook;
};

std::ostream& operator<<(std::ostream&, Priest&);

#endif // PRIEST_H
