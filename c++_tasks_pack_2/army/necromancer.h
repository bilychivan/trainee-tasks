#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include <string>
#include "creature.h"
#include "skeleton.h"
#include "spellbook.h"

class Necromancer : public Creature
{
    public:
        Necromancer(std::string argName);

        virtual const std::string getClassName() const override {return "Necromancer";}

        Spellbook spellbook;
};

std::ostream& operator<<(std::ostream&, Necromancer&);

#endif // NECROMANCER_H
