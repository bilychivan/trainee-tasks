#include "necromancer.h"
#include "colors.h"

Necromancer::Necromancer(std::string argName) : Creature(argName), spellbook(*this)
{
    setStat(Creature::Stats::DamageType, DamageType::Magic);
    setStat(Creature::Stats::ArmorType, ArmorType::Cloth);
    spellbook.addSpell(Spell::SummonSkeleton);
}

std::ostream& operator<<(std::ostream& stream, Necromancer& object)
{
    stream << (Creature&)object;

    return stream;
}