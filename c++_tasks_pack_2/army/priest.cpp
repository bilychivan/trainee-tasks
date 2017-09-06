#include "priest.h"
#include "colors.h"

Priest::Priest(std::string argName) : Creature(argName), spellbook(*this)
{
    setStat(Creature::Stats::DamageType, DamageType::Magic);
    setStat(Creature::Stats::ArmorType, ArmorType::Cloth);
    setStat(Creature::Stats::Intellegence, 5);
    spellbook.addSpell(Spell::Heal);
}

std::ostream& operator<<(std::ostream& stream, Priest& object)
{
    stream << (Creature&)object;

    return stream;
}