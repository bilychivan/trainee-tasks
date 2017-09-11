#include "fireball.h"
#include "magicUnit.h"

void Fireball::magicSpell(MagicUnit *executor, Unit *target)
{
    int enemyHp = target->getHp();
    int damage;

    if (enemyHp <= 0)
    {
        std::cout << DELIMETER << target->getClassName() << " killed" << std::endl;

        return;
    }
    if (executor->getHp() <= 0)
    {
        std::cout << DELIMETER << executor->getClassName() << " killed" << std::endl;

        return;
    }

    damage = executor->getMagicPower() * FIREBALL_POWER;

    if (damage > enemyHp)
    {
        damage = enemyHp;
    }

    executor->calculatedAttack(target, enemyHp, damage);

    target->counterAttack(executor);
    std::cout  << std::endl;
}