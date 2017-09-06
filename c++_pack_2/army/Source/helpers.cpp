#include "helpers.h"
#include "category.h"
#include "healer.h"

#include <cstdlib>
#include <cassert>

void displayEntities(const std::vector<Entity::Ptr>& array)
{
    for (const auto& entity : array)
    {
        std::cout << "    " << getName(entity) << "_hp: " << entity->getHitpoints() << std::endl;
    }
}

void entitiesAttacks(Entity::Ptr& first, Entity::Ptr& second)
{
    std::cout << getName(first) << " attacks " << getName(second) << std::endl;

    first->attack(second);
}

void entitiesCastSpells(const Entity::Ptr& first, Entity::Ptr& second)
{
    const Caster& caster = dynamic_cast<Caster&>(*first);

    std::cout << getName(first) << " castSpells " << getName(second) << std::endl;

    caster.castSpell(second);
}

void entitiesHeals(const Entity::Ptr& first, Entity::Ptr& second)
{
    const Healer& healer = dynamic_cast<Healer&>(*first);

    std::cout << getName(first) << " heals " << getName(second) << std::endl;

    healer.heal(second);
}

CATEGORY::ID getRandomGategory()
{
    return CATEGORY::ID(1 << (rand() % CATEGORY::COUNT));
}

Entity::Ptr getEntity(CATEGORY::ID id, int hitpoints, int damage)
{
    switch(id)
    {
        case CATEGORY::SKELETON:
            return Entity::Ptr(new Skeleton(hitpoints, damage));
        case CATEGORY::WARRIOR:
            return Entity::Ptr(new Warrior(hitpoints, damage));
        case CATEGORY::ARCHER:
            return Entity::Ptr(new Archer(hitpoints, damage));
        case CATEGORY::MAGE:
            return Entity::Ptr(new Mage(hitpoints, damage));
        case CATEGORY::WARLOCK:
            return Entity::Ptr(new Warlock(hitpoints, damage));
        case CATEGORY::VAMPIRE:
            return Entity::Ptr(new Vampire(hitpoints, damage));
        case CATEGORY::HEALER:
            return Entity::Ptr(new Healer(hitpoints, damage));
    }

    assert(false);
}

const char* getName(const Entity::Ptr& entity)
{
    switch(entity->getCategory())
    {
        case CATEGORY::SKELETON:
            return "SKELETON";
        case CATEGORY::WARRIOR:
            return "WARRIOR";
        case CATEGORY::ARCHER:
            return "ARCHER";
        case CATEGORY::MAGE:
            return "MAGE";
        case CATEGORY::WARLOCK:
            return "WARLOCK";
        case CATEGORY::VAMPIRE:
            return "VAMPIRE";
        case CATEGORY::HEALER:
            return "HEALER";
    }
}