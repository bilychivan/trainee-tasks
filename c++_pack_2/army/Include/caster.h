#ifndef CASTER_CLASS_H
#define CASTER_CLASS_H

#include "entity.h"

#include <functional>

class Caster : public Entity
{
public:
    using Spell = std::function<void(Entity::Ptr& entity)>;

    Caster(int hitpoints, ARMOR_TYPE armor, int damage, Spell spell);

    void castSpell(Entity::Ptr& entity) const;
    void setSpell(Spell spell);

protected:
    Spell mSpell;
};

#endif