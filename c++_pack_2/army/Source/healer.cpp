#include "healer.h"

const int Healer::defaultHealingPower = 3;

Healer::Healer(int hitpoints, int damage)
    : Entity(hitpoints, ARMOR_TYPE::NORMAL, damage), mHealingPower(defaultHealingPower)
{

}

void Healer::attack(Ptr& entity)
{
    throw HealerException("heal can't attack");
}

int Healer::getCategory() const
{
    return CATEGORY::HEALER;
}

void Healer::heal(Entity::Ptr& entity) const
{
    entity->restore(getHealingPower());
}

void Healer::setHealingPower(int healingPower)
{
    if (healingPower < 0)
    {
        throw HealerException("healingPower can't be less than zero: " + std::to_string(healingPower));
    }

    mHealingPower = healingPower;
}

int Healer::getHealingPower() const
{
    return mHealingPower;
}

HealerException::HealerException(const std::string& message)
    : EntityException(message)
{

}