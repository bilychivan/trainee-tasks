#ifndef WARLOCK_CLASS_H
#define WARLOCK_CLASS_H

#include "caster.h"

class Warlock : public Caster
{
public:
    Warlock(int hitpoints, int damage);

    virtual int getCategory() const override;
};

class WarlockException : public EntityException
{
public:
    explicit WarlockException(const std::string& message);
};

#endif