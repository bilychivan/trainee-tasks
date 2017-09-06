#ifndef SPELLS_H
#define SPELLS_H

#include "creature.h"
#include <memory>

struct SpellResult
{
    bool spellSuccessful;
    std::unique_ptr<Creature> summonedCreature;

    SpellResult() : spellSuccessful(false), summonedCreature(std::unique_ptr<Creature>()) {}
};

enum class Spell
{
    Heal,
    SummonSkeleton
};

const unsigned int SpellCount = 2;

extern const char* SpellStrings[SpellCount];

SpellResult SpellHeal(Creature& caster, Creature& target);
SpellResult SpellSummonSkeleton(Creature& caster, Creature& target);

extern SpellResult (*SpellHandlers[SpellCount])(Creature& caster, Creature& target);

#endif // SPELLS_H
