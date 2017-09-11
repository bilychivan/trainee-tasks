#include "skeleton.h"

Skeleton::Skeleton() : Unit(HP::LOW, ARMOR::WEAK, SKELETON_ATT) {};

std::string Skeleton::getClass() const
{
    return this->className;
}

const std::string Skeleton::className = "Skeleton";