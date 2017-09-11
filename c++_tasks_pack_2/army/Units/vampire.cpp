#include "vampire.h"

Vampire::Vampire() : Unit(MIDDLE, MEDIUM, VAMPIRE_ATTACK) {};

const std::string &Vampire::getClassName() const
{
    return this->className;
}

void Vampire::attack(Unit &enemy)
{
    int enemyHp = enemy.getHp();
    int damage = attackPower - enemy.getDefence() * attackPower / 100;

    if (damage > enemyHp)
    {
        damage = enemyHp;
    }

    if (enemyHp > 0)
    {
        int currentHp = enemyHp - damage;

        enemy.setHp(currentHp);
        std::cout << getClassName() << " hit " << damage << " damage " << "to " << enemy.getClassName() << std::endl;

        this->setHp(this->currentHp + (damage / VAMPIRE_DRAIN_POWER));

        if (currentHp <= 0)
        {
            std::cout << getClassName() << " killed the " << enemy.getClassName() << std::endl;
        }
    }
    else
    {
        std::cout << enemy.getClassName() << " killed" << std::endl;
    }
}

const std::string Vampire::className = "Vampire";