#include "entity.h"

#include <algorithm>

Entity::Entity(int hitpoints, ARMOR_TYPE armor, int damage, bool resisted)
    : mHitpoints(hitpoints), mMaxHitpoints(hitpoints), mArmor(armor), mDamage(damage), mResisted(resisted)
{

}

Entity::~Entity()
{

}

void Entity::attack(Ptr& entity)
{
    entity->takeDamage(getDamage());

    intermediateAction(entity);

    entity->counterAttack(this);
}

void Entity::counterAttack(Entity* entity) const
{
    if (entity->mResisted)
    {
        entity->takeDamage(mDamage / 2);
    }
}

void Entity::setDamage(int damage)
{
    if (damage < 0)
    {
        throw EntityException("damage can't be less than zero: " + std::to_string(damage));
    }

    mDamage = damage;
}

int Entity::getDamage() const
{
    return mDamage;
}

void Entity::takeDamage(int damage)
{
    if (damage < mArmor)
    {
        throw EntityException("damage can't be less than armor: " + std::to_string(damage));
    }

    mHitpoints -= damage - mArmor;
}

void Entity::takeMagicDamage(int damage)
{
    if (damage <= 0)
    {
        throw EntityException("damage must be positive: " + std::to_string(damage));
    }

    mHitpoints -= damage;
}

void Entity::restore(int hitpoints)
{
    if (isDestroyed())
    {
        throw EntityException("attempt to restore an already dead entity");
    }
    else if (hitpoints <= 0)
    {
        throw EntityException("restoration hitpoints must be positive: " + std::to_string(hitpoints));
    }

    mHitpoints = std::min(mHitpoints + hitpoints, mMaxHitpoints);
}

int Entity::getHitpoints() const
{
    return mHitpoints;
}

bool Entity::isDestroyed() const
{
    return mHitpoints <= 0;
}

int Entity::getArmor() const
{
    return mArmor;
}

void Entity::intermediateAction(Ptr& entity)
{

}

EntityException::EntityException(const std::string& message)
    : std::runtime_error(message)
{

}