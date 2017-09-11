#ifndef UNIT_H
#define UNIT_H

#include "armyException.h"

#define DELIMETER "----"

enum ARMOR {WEAK = 20, MEDIUM = 30, STRONG = 40};
enum HP {LOW = 120, MIDDLE = 160, HIGH = 200};

class Unit
{
private:
    static int serial;
    const int id;
    static const int percentForCalculating = 100;
    static const int percentOfCounterAttack = 50;
    static const int percentToChanceToCrit = 20;
    static const int multipleOfCritAttack = 2;

protected:
    int currentHp;
    int defence;
    int attackPower;
    int maxHp;
    bool chanceToCrit;
    bool resistanceToCounter;

public:
    Unit();
    Unit(int hp, int defence, int attackPower);

    void print_hp();

    int getHp() const;
    int getMaxHp() const;
    int getId() const;
    int getDefence() const;
    int getAttackPower() const;
    virtual const std::string &getClassName() const = 0;

    void setHp(int newHp);
    void setAttackPower(int newAttack);
    void setDefence(int newDefence);

    virtual void counterAttack(Unit *enemy);
    virtual void attack(Unit *enemy);
    void calculatedAttack(Unit *enemy, int enemyHp, int damage);
    bool calcCrit();
    int calcDamage(int enemyHp, int enemyDefence, bool crit);
};

std::ostream& operator<<(std::ostream& os, const Unit& obj);

#endif //UNIT_H
