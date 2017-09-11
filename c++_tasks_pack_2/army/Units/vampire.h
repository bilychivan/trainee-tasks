#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "unit.h"

#define VAMPIRE_ATTACK 40
#define VAMPIRE_DRAIN_POWER 3

class Vampire : public Unit
{
private:
    const static std::string className;

public:
    Vampire();
    std::string getClass() const override;
    void attack(Unit &enemy);
};

#endif // VAMPIRE_H