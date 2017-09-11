#include "magicUnit.h"

MagicUnit::MagicUnit(int hp, int defence, int attackPower, int magicPower) :
        Unit(hp, defence, attackPower) , magicPower(magicPower) {};

std::map<int , Spell*> &MagicUnit::getSpellbook()
{
    return spellbook;
}

void MagicUnit::castSpell(SpellName spell, Unit *enemy)
{
    if (spellbook[spell])
    {
        spellbook[spell]->magicSpell(this, enemy);
    }
    else
    {
        throw ArmyException("Unit can not do this spell");
    }
}

void MagicUnit::attack(Unit *enemy)
{
    int enemyHp = enemy->getHp();
    int damage;

    if (enemyHp <= 0)
    {
        std::cout << DELIMETER << enemy->getClassName() << " killed" << std::endl;

        return;
    }
    if (this->currentHp <= 0)
    {
        std::cout << DELIMETER << this->getClassName() << " killed" << std::endl;

        return;
    }

    damage = magicPower;

    if (damage > enemyHp)
    {
        damage = enemyHp;
    }

    calculatedAttack(enemy, enemyHp, damage);

    enemy->counterAttack(this);
    std::cout  << std::endl;
}

int MagicUnit::getMagicPower() const
{
    return  magicPower;
}

void MagicUnit::setMagicPower(int newMagicPower)
{
    this->magicPower = newMagicPower;
}