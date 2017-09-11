#ifndef SPELL_H
#define SPELL_H

#include "unit.h"

class MagicUnit;

class Spell
{
public:
    virtual void magicSpell(MagicUnit *executor, Unit *target) = 0;;
};

#endif //SPELL_H
