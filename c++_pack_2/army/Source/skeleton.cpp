#include "skeleton.h"

Skeleton::Skeleton(int hitpoints, int damage)
    : Entity(hitpoints, ARMOR_TYPE::NORMAL, damage)
{

}

CATEGORY::ID Skeleton::getCategory() const
{
    return CATEGORY::SKELETON;
}