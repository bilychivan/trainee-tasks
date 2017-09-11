#include "vampire.h"

Vampire::Vampire() : Unit(MIDDLE, MEDIUM, VAMPIRE_ATTACK) {};

std::string Vampire::getClass() const
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
        std::cout << getClass() << " hit " << damage << " damage " << "to " << enemy.getClass() << std::endl;

        this->setHp(this->currentHp + (damage / VAMPIRE_DRAIN_POWER));

        if (currentHp <= 0)
        {
            std::cout << getClass() << " killed the " << enemy.getClass() << std::endl;
        }
    }
    else
    {
        std::cout << enemy.getClass() << " killed" << std::endl;
    }
}

const std::string Vampire::className = "Vampire";