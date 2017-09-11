#include "unit.h"

int Unit::serial = 1;

Unit::Unit() :
        currentHp(0), maxHp(0), defence(0), attackPower(0), id(serial++) {};

Unit::Unit(int nHp, int nDefence, int nAttack) :
        currentHp(nHp), maxHp(nHp), defence(nDefence), attackPower(nAttack),
        id(serial++) {};

void Unit::calculatedAttack(Unit *enemy, int enemyHp, int damage)
{
    int clearHp = enemyHp - damage;

    enemy->setHp(clearHp);
    std::cout << getClassName() << " hit " << damage << " damage " << "to " << enemy->getClassName();
    if (clearHp <= 0)
    {
        std::cout << std::endl << DELIMETER << getClassName() << " killed the " << enemy->getClassName();
    }
}

bool Unit::calcCrit()
{
    int randN;

    if (!this->chanceToCrit)
    {
        return false;
    }

    randN = std::rand();

    return randN % 100 <= percentToChanceToCrit;
}

int Unit::calcDamage(int enemyHp, int enemyDefence, bool crit)
{
    int damage;
    int clearAttack;

    if (crit)
    {
        clearAttack = attackPower * multipleOfCritAttack;
    }
    else
    {
        clearAttack = attackPower;
    }

    damage = clearAttack -  enemyDefence * clearAttack / percentForCalculating;

    if (damage > enemyHp)
    {
        damage = enemyHp;
    }

    return damage;
}

void Unit::attack(Unit *enemy)
{
    int enemyHp = enemy->getHp();
    int damage;
    bool critAttack;

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

    critAttack = calcCrit();
    damage = calcDamage(enemyHp, enemy->getDefence(), critAttack);

    if (damage > enemyHp)
    {
        damage = enemyHp;
    }

    calculatedAttack(enemy, enemyHp, damage);

    if (!this->resistanceToCounter)
    {
        enemy->counterAttack(this);
    }

    std::cout << std::endl;
}

void Unit::counterAttack(Unit *enemy)
{
    int enemyHp = enemy->getHp();
    int damage;

    if (enemyHp <= 0)
    {
        return;
    }
    if (this->currentHp <= 0)
    {
        return;
    }

    damage = (attackPower - enemy->getDefence() * attackPower / percentForCalculating) / (percentForCalculating / percentOfCounterAttack);

    if (damage > enemyHp)
    {
        damage = enemyHp;
    }

    std::cout << std::endl << DELIMETER << "Counterattack: ";
    calculatedAttack(enemy, enemyHp, damage);
}

void Unit::print_hp()
{
    std::cout << getClassName() << ' ' << currentHp << std::endl;
}

int Unit::getHp() const
{
    return currentHp;
}

int Unit::getMaxHp() const
{
    return maxHp;
}

int Unit::getId() const
{
    return  id;
}

int Unit::getDefence() const
{
    return defence;
}

int Unit::getAttackPower() const
{
    return attackPower;
}

void Unit::setDefence(int newDefence)
{
    this->defence = newDefence;
}
void Unit::setAttackPower(int newAttack)
{
    this->attackPower = newAttack;
}

void Unit::setHp(int newHp)
{
    if (newHp > maxHp)
    {
        this->currentHp = maxHp;
    }
    else if (newHp < 0)
    {
        this->currentHp = 0;
    }
    else
    {
        this->currentHp = newHp;
    }
}

std::ostream& operator<<(std::ostream& os, const Unit& obj)
{
    os << DELIMETER << DELIMETER << obj.getClassName() << DELIMETER << DELIMETER << std::endl;
    os << "Id: " << obj.getId() << std::endl;
    os << "Hp: " << obj.getHp() << " of " << obj.getMaxHp() << std::endl;
    os << "AttackPower: " << obj.getAttackPower() << std::endl;
    os << "Defence: " << obj.getDefence() << std::endl;

    return os;
}