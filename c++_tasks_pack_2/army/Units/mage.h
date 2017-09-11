#ifndef MAGE_H
#define MAGE_H

#include "magicUnit.h"

#define MAGE_ATTACK 0
#define MAGE_MAGIC_POWER 70

class Mage : public MagicUnit
{
private:
    const static std::string className;

public:
    Mage();
    const std::string &getClassName() const override;
};

#endif // MAGE_H