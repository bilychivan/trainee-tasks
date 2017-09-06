#ifndef HEALER_CLASS_H
#define HEALER_CLASS_H

#include "entity.h"

class Healer : public Entity
{
public:
    Healer(int hitpoints, int damage);

    virtual void attack(Ptr& entity) override;

    virtual int getCategory() const override;

    void heal(Entity::Ptr& entity) const;

    void setHealingPower(int healingPower);
    int getHealingPower() const;

private:
    static const int defaultHealingPower;

    int mHealingPower;
};

class HealerException : public EntityException
{
public:
    explicit HealerException(const std::string& message);
};

#endif