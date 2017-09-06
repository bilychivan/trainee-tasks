#ifndef WARRIOR_CLASS_H
#define WARRIOR_CLASS_H

#include "entity.h"

class Warrior : public Entity
{
public:
    Warrior(int hitpoints, int damage);

    virtual int getCategory() const override;

    void setDoubleDamageChance(int chance);
    int getDoubleDamageChance() const;

protected:
    virtual void intermediateAction(Ptr& entity) override;

private:
    static const int defaultChance;
    static const int minChance;
    static const int maxChance;

    int mDoubleDamageChance;
};

class WarriorException : public EntityException
{
public:
    explicit WarriorException(const std::string& message);
};

#endif