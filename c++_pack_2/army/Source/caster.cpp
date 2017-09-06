#include "caster.h"

Caster::Caster(int hitpoints, ARMOR_TYPE armor, int damage, Spell spell)
    : Entity(hitpoints, armor, damage), mSpell(spell)
{

}

void Caster::castSpell(Entity::Ptr& entity) const
{
    mSpell(entity);
}

void Caster::setSpell(Spell spell)
{
    mSpell = spell;
}