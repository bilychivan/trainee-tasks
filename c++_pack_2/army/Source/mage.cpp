#include "mage.h"

const int Mage::defaultBlastDamage = 7;

Mage::Mage(int hitpoints, int damage)
    : Caster(hitpoints, ARMOR_TYPE::NORMAL, damage, [this](Entity::Ptr& entity)
    {
        entity->takeMagicDamage(getBlastDamage());
    }), mBlastDamage(defaultBlastDamage)
{

}

CATEGORY::ID Mage::getCategory() const
{
    return CATEGORY::MAGE;
}

void Mage::setBlastDamage(int blastDamage)
{
    if (blastDamage <= 0)
    {
        throw MageException("blastDamage must be more than zero: " + std::to_string(blastDamage));
    }

    mBlastDamage = blastDamage;
}

int Mage::getBlastDamage() const
{
    return mBlastDamage;
}

MageException::MageException(const std::string& message)
    : EntityException(message)
{

}