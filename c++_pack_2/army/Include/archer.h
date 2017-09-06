#ifndef ARCHER_CLASS_H
#define ARCHER_CLASS_H

#include "entity.h"

class Archer : public Entity
{
public:
    Archer(int hitpoints, int damage);

    virtual CATEGORY::ID getCategory() const override;
};

#endif