#include "heal.h"
#include "magicUnit.h"

void Heal::magicSpell(MagicUnit *executor, Unit *target)
{
    int currentTargetHp = target->getHp();
    int healPower = executor->getMagicPower();

    if (currentTargetHp > 0)
    {
        target->setHp(currentTargetHp + healPower);
        std::cout << executor->getClassName() << " heals " << target->getClassName() << " at " << healPower << " hp" << std::endl;
    }
    else
    {
        throw ArmyException("Can not heal because the target is dead");
    }
}