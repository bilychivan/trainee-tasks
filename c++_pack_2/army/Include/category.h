#ifndef CATEGORY_H
#define CATEGORY_H

namespace CATEGORY
{
    enum ID
    {
        SKELETON = 1 << 0,
        WARRIOR = 1 << 1,
        ARCHER = 1 << 2,
        MAGE  = 1 << 3,
        WARLOCK = 1 << 4,
        VAMPIRE  = 1 << 5,
        HEALER = 1 << 6,
        DAMAGER = SKELETON | WARRIOR | ARCHER | VAMPIRE,
        CASTER = MAGE | WARLOCK,

        COUNT = 7
    };
}

#endif