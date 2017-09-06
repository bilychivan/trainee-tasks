#include "warlock.h"
#include "skeleton.h"

Warlock::Warlock(int hitpoints, int damage)
    : Caster(hitpoints, ARMOR_TYPE::NORMAL, damage, [this](Entity::Ptr& entity)
    {
        if (!entity->isDestroyed())
        {
            throw WarlockException("warlock can't resurrect alive entity");
        }

        Entity::Ptr skeleton(new Skeleton(15, 10));
        entity = std::move(skeleton);
    })
{

}

int Warlock::getCategory() const
{
    return CATEGORY::WARLOCK;
}

WarlockException::WarlockException(const std::string& message)
    : EntityException(message)
{

}