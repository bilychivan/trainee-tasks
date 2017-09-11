#ifndef WARRIOR_H
#define WARRIOR_H

#include "unit.h"

#define WARRIOR_ATTACK 35
#define CHANCE_TO_CRIT 20
#define CRIT_MULTIPLE 2

class Warrior : public Unit
{
private:
    const static std::string className;

public:
    Warrior();

    const std::string &getClassName() const override;
};

#endif // WARRIOR_H