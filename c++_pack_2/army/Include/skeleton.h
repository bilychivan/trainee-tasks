#ifndef SKELETON_CLASS_H
#define SKELETON_CLASS_H

#include "entity.h"

class Skeleton : public Entity
{
public:
    Skeleton(int hitpoints, int damage);

    virtual CATEGORY::ID getCategory() const override;
};

#endif