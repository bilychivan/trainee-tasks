#ifndef PRIEST_H
#define PRIEST_H

#include "magicUnit.h"

#define PRIEST_ATTACK 0
#define PRIEST_MAGIC_POWER 20

class Priest : public MagicUnit
{
private:
    const static std::string className;

public:
    Priest();

    const std::string &getClassName() const override;
    void attack(Unit *enemy) override;
    void counterAttack(Unit *enemy) override;
};

#endif // MAGE_H