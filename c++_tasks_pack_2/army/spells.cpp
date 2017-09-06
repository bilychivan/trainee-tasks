#include <memory>
#include "spells.h"
#include "colors.h"
#include "skeleton.h"

const char* SpellStrings[SpellCount] =
{
    "Heal",
    "Summon Skeleton"
};

SpellResult (*SpellHandlers[SpellCount])(Creature& caster, Creature& target)
{
    SpellHeal,
    SpellSummonSkeleton
};

SpellResult SpellHeal(Creature& caster, Creature& target)
{
    SpellResult result;

    if (target.isAlive() == false)
    {
        result.spellSuccessful = false;

        return result;
    }

    result.spellSuccessful = true;

    int HealingPower = caster.getStat(Creature::Stats::Intellegence);

    std::cout << BOLD(FGRN(<< caster.getName() <<)) << " healed " << BOLD(FGRN(<< target.getName() <<)) " for " << FGRN(<< HealingPower <<) << " "
              << Creature::StatsStrings[static_cast<int>(Creature::Stats::Health)] << " points" << std::endl;

    target.setStat(Creature::Stats::Health, target.getStat(Creature::Stats::Health) + HealingPower);

    return result;
}

SpellResult SpellSummonSkeleton(Creature& caster, Creature& target)
{
    SpellResult result;

    if (target.isAlive())
    {
        throw CreatureException("Cannot summon skeleton, target is alive");
    }

    if (target.isCorpse() == false)
    {
        throw CreatureException("Cannot summon skeleton, target has no corpse");
    }

    std::string skeletonsName = caster.getName() + "'s minion";
    std::unique_ptr<Skeleton> skeleton = std::make_unique<Skeleton>(skeletonsName);
    skeleton->setStat(Creature::Stats::MaxHealth, caster.getStat(Creature::Stats::MaxHealth) / 2.);
    skeleton->setStat(Creature::Stats::Attack, caster.getStat(Creature::Stats::Attack) / 2.);
    skeleton->setStat(Creature::Stats::Armor, caster.getStat(Creature::Stats::Armor) / 2.);

    std::cout << BOLD(FGRN(<< caster.getName() <<)) << " raised the skeleton from " << BOLD(FGRN(<< target.getName() <<)) << "'s corpse" << std::endl;

    target.setCorpse(false);
    skeleton->setCorpse(false);

    result.spellSuccessful = true;
    result.summonedCreature = std::move(skeleton);
    return result;
}