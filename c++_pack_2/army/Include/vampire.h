#ifndef VAMPIRE_CLASS_H
#define VAMPIRE_CLASS_H

#include "entity.h"

class Vampire : public Entity
{
public:
    Vampire(int hitpoints, int damage);

    virtual CATEGORY::ID getCategory() const override;

    virtual void takeMagicDamage(int damage) override;

    void setLifestealRate(double rate);
    double getLifestealRate() const;

protected:
    virtual void intermediateAction(Ptr& entity) override;

private:
    static const double defaultLifestealRate;

    double mLifestealRate;
};

class VampireException : public EntityException
{
public:
    explicit VampireException(const std::string& message);
};

#endif