#ifndef WARLOCK_H
#define WARLOCK_H

#include "magicUnit.h"
#include "skeleton.h"

#define WARLOCK_ATTACK 5
#define WARLOCK_MAGIC_POWER 30

class Warlock : public MagicUnit
{
private:
    const static std::string className;

public:
    Warlock();

    const std::string &getClassName() const override;
};

#endif // WARLOCK_H