#ifndef ARMY_MAGICUNIT_H
#define ARMY_MAGICUNIT_H

#include <map>
#include "unit.h"
#include "skeleton.h"
#include "summonSkeleton.h"
#include "heal.h"

enum SpellName
{
    heal = 1,
    fireball,
    summonSkeleton
};

class Spell;

class MagicUnit : public Unit
{
protected:
    int magicPower;
    std::map<int , Spell*> spellbook;

public:
    MagicUnit(int hp, int defence, int attackPower, int magicPower);

    void attack(Unit *enemy) override;

    int getMagicPower() const;
    void setMagicPower(int newMagicPower);
    void castSpell(SpellName spell, Unit *enemy);
    std::map<int , Spell*> getSpellbook();

    Unit *slave;
};

#endif //ARMY_MAGICUNIT_H

