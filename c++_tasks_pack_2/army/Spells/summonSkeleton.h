#ifndef SUMMONSKELETON_H
#define SUMMONSKELETON_H

#include "spell.h"

class SummonSkeleton : public Spell
{
public:
    void magicSpell(MagicUnit *executor, Unit *target) override;
};

#endif //SUMMONSKELETON_H
