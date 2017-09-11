#include "summonSkeleton.h"
#include "magicUnit.h"

void SummonSkeleton::magicSpell(MagicUnit *executor, Unit *target)
{
    if (target->getHp() == 0)
    {
        Unit *newObject = new Skeleton;

        if (executor->getSpellbook()[SpellName ::summonSkeleton])
        {
            executor->slave = newObject;
        }
    }
    else
    {
        throw ArmyException("Unit is still alive!");
    }
}