#include "warrior.h"
#include "archer.h"
#include "mage.h"
#include "priest.h"
#include "warlock.h"
#include "skeleton.h"
#include "vampire.h"
#include <vector>

void testArmy()
{
    Unit *archerUnit = new Archer();
    Unit *warriorUnit = new Warrior();
    MagicUnit *mageUnit = new Mage();
    MagicUnit *pristUnit = new Priest();
    Unit *skeletonUnit = new Skeleton();
    Unit *vampireUnit = new Vampire();
    MagicUnit *warlockUnit = new Warlock();

    std::cout << *vampireUnit << std::endl;

    std::vector<Unit *> array;
    array.push_back(new Warlock);
    try {
        ((MagicUnit *)(array[0]))->castSpell(SpellName::summonSkeleton, vampireUnit);
    }
    catch (ArmyException obj)
    {
        std::cout << obj.what() << std::endl;
    }
    Warrior *newWar = new Warrior();
    Unit* arr[8];
    arr[0] = archerUnit;
    arr[1] = warriorUnit;
    arr[2] = mageUnit;
    arr[3] = pristUnit;
    arr[4] = skeletonUnit;
    arr[5] = vampireUnit;
    arr[6] = warlockUnit;
    arr[7] = newWar;

    arr[7]->print_hp();
    archerUnit->attack(warriorUnit);
    archerUnit->attack(warriorUnit);
    archerUnit->attack(warriorUnit);
    archerUnit->attack(warriorUnit);
    archerUnit->attack(warriorUnit);
    archerUnit->attack(warriorUnit);
    archerUnit->attack(warriorUnit);

    warriorUnit->print_hp();
    Priest newPriest;

    newPriest.castSpell(SpellName::heal, warriorUnit);
    warriorUnit->print_hp();
    archerUnit->attack(warriorUnit);
    mageUnit->attack(warriorUnit);
    mageUnit->attack(warriorUnit);
    mageUnit->attack(warriorUnit);
    mageUnit->attack(warriorUnit);
    mageUnit->attack(warriorUnit);
    mageUnit->attack(warriorUnit);
    warriorUnit->print_hp();

    Mage mage2;
    mage2.print_hp();
    warlockUnit->castSpell(SpellName::summonSkeleton, warriorUnit);
    warlockUnit->slave->print_hp();

    try
    {
        pristUnit->castSpell(SpellName::summonSkeleton, warriorUnit);
    }
    catch(ArmyException obj)
    {
        std::cout << obj.what() << std::endl;
    }
    try
    {
        newPriest.castSpell(SpellName ::heal, warriorUnit);
    }
    catch(ArmyException obj)
    {
        std::cout << obj.what() << std::endl;
    }
    try
    {
        newPriest.attack(warlockUnit);
    }
    catch(ArmyException obj)
    {
        std::cout << obj.what() << std::endl;
    }
    archerUnit->attack(vampireUnit);
    archerUnit->attack(vampireUnit);
    archerUnit->attack(vampireUnit);
    vampireUnit->print_hp();
    pristUnit->print_hp();
    vampireUnit->attack(pristUnit);
    vampireUnit->print_hp();
    pristUnit->print_hp();
    vampireUnit->attack(pristUnit);
    vampireUnit->print_hp();
    pristUnit->print_hp();
    vampireUnit->attack(pristUnit);
    vampireUnit->print_hp();
    pristUnit->print_hp();
    vampireUnit->attack(pristUnit);
    vampireUnit->print_hp();
    pristUnit->print_hp();
}

int main ()
{
    try
    {
        testArmy();
    }
    catch(ArmyException obj)
    {
        std::cout << obj.what() << std::endl;
    }
}