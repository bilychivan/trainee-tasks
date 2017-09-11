#ifndef HEAL_H
#define HEAL_H

#include "unit.h"
#include "spell.h"

class MagicUnit;

class Heal : public Spell
{
public:
    void magicSpell(MagicUnit *executor, Unit *target) override;
};

#endif //HEAL_H
