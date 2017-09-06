#include "archer.h"

Archer::Archer(int hitpoints, int damage)
    : Entity(hitpoints, ARMOR_TYPE::WEAK, damage, false)
{

}

CATEGORY::ID Archer::getCategory() const
{
    return CATEGORY::ARCHER;
}