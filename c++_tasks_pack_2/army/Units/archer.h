#ifndef ARCHER_H
#define ARCHER_H

#include "unit.h"

#define ARCHER_ATTACK 30


class Archer : public Unit
{
private:
    const static std::string className;

public:
    Archer();
    const std::string &getClassName() const override;
};

#endif // ARCHER_H