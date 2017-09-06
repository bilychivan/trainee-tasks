#include "vampire.h"

const double Vampire::defaultLifestealRate = 0.25;

Vampire::Vampire(int hitpoints, int damage)
    : Entity(hitpoints, ARMOR_TYPE::NORMAL, damage), mLifestealRate(defaultLifestealRate)
{

}

int Vampire::getCategory() const
{
    return CATEGORY::VAMPIRE;
}

void Vampire::takePureDamage(int damage)
{
    Entity::takePureDamage(damage * 2);
}

void Vampire::setLifestealRate(double rate)
{
    if (rate <= 0)
    {
        throw VampireException("rate must be positive: " + std::to_string(rate));
    }

    mLifestealRate = rate;
}

double Vampire::getLifestealRate() const
{
    return mLifestealRate;
}

void Vampire::intermediateAction(Ptr& that)
{
    restore((getDamage() - that->getArmor()) * getLifestealRate());
}

VampireException::VampireException(const std::string& message)
    : EntityException(message)
{

}