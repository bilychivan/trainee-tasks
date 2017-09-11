#ifndef FIREBALL_H
#define FIREBALL_H

#include "spell.h"

#define FIREBALL_POWER 2

class Fireball : Spell
{
public:
    void magicSpell(MagicUnit *executor, Unit *target) override;
};

#endif //FIREBALL_H
