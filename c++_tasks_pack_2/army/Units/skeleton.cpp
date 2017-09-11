#include "skeleton.h"

Skeleton::Skeleton() : Unit(HP::LOW, ARMOR::WEAK, SKELETON_ATT) {};

const std::string &Skeleton::getClassName() const
{
    return this->className;
}

const std::string Skeleton::className = "Skeleton";