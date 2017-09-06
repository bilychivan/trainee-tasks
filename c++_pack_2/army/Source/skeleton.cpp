#include "skeleton.h"

Skeleton::Skeleton(int hitpoints, int damage)
    : Entity(hitpoints, ARMOR_TYPE::NORMAL, damage)
{

}

int Skeleton::getCategory() const
{
    return CATEGORY::SKELETON;
}