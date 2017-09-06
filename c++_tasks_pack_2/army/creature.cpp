#include "creature.h"
#include "colors.h"

const char *Creature::StatsStrings[StatsCount] =
{
    "Health",
    "Max Health",
    "Attack",
    "Armor",
    "Intellegence",
    "Damage type",
    "Armor type"
};

const char *Creature::DamageTypeStrings[] =
{
    "Melee",
    "Ranged",
    "Magic"
};

const char *Creature::ArmorTypeStrings[] =
{
    "Cloth",
    "Leather",
    "Plate",
    "Unarmored"
};

const float Creature::ArmorTypeMultiplier[Creature::ArmorTypeCount] =
{
    0.75,
    1.0,
    1.25,
    0.5
};

const bool Creature::StatDisplayByValue[StatsCount] =
{
    true,
    true,
    true,
    true,
    true,
    false,
    false
};

const char* Creature::StatUndefined = "Undefined";

Creature::Creature(std::string argName)
{
    alive = true;
    corpse = true;

    if (argName.length() > 0)
    {
        name = argName;
    }
    else
    {
        name = "Undefined";
    }

    stats.reserve(StatsCount);
    for (unsigned int i = 0; i < StatsCount; i++)
    {
        Stat tmp;

        tmp.value = 0;
        tmp.name = Creature::StatUndefined;

        stats.push_back(tmp);
    }
}

void Creature::setStat(Stats statNo, float value)
{
    if (statNo == Stats::Health)
    {
        if (value > stats[static_cast<int>(Stats::MaxHealth)].value)
        {
            value = stats[static_cast<int>(Stats::MaxHealth)].value;
        }

        if (value > 0)
        {
            alive = true;
        }
        else
        {
            alive = false;
        }
    }
    else if (statNo == Stats::MaxHealth)
    {
        stats[static_cast<int>(Stats::Health)].value = value;
        stats[static_cast<int>(Stats::Health)].name = StatsStrings[static_cast<int>(Stats::Health)];
    }

    stats[static_cast<int>(statNo)].value = value;

    if (stats[static_cast<int>(statNo)].name == StatUndefined)
    {
        switch (statNo)
        {
            case Stats::DamageType:
            {
                stats[static_cast<int>(statNo)].name = DamageTypeStrings[static_cast<int>(value)];
                break;
            }

            case Stats::ArmorType:
            {
                stats[static_cast<int>(statNo)].name = ArmorTypeStrings[static_cast<int>(value)];
                break;
            }

            default:
            {
                stats[static_cast<int>(statNo)].name = StatsStrings[static_cast<int>(statNo)];
                break;
            }
        }
    }
}

void Creature::setStat(Stats statNo, DamageType value)
{
    setStat(statNo, static_cast<float>(value));
}

void Creature::setStat(Stats statNo, ArmorType value)
{
    setStat(statNo, static_cast<float>(value));
}

const float Creature::getStat(Stats statNo) const
{
    return stats[static_cast<int>(statNo)].value;
}

const std::string& Creature::getName() const
{
    return name;
}

const std::vector<Creature::Stat>& Creature::getStats() const
{
    return stats;
}

const Creature::DamageType Creature::getDamageType() const
{
    return DamageType(static_cast<int>(getStat(Stats::DamageType)));
}

const bool Creature::isAlive() const
{
    return alive;
}

const bool Creature::isCorpse() const
{
    return corpse;
}

void Creature::setCorpse(bool status)
{
    corpse = status;
}

bool Creature::Attack(Creature& target)
{
    return Attack(target, 1);
}

bool Creature::Attack(Creature& target, float damageMultiplier)
{
    if (alive == false)
    {
        throw CreatureException("Failed to attack with the dead unit");
    }

    if (target.alive == false)
    {
        throw CreatureException("Failed to attack a dead unit");
    }

    if ((getDamageType() == Creature::DamageType::Magic) && (target.MagicDamageReceivedMultiplier() != 1))
    {
        damageMultiplier *= target.MagicDamageReceivedMultiplier();
    }

    float damageAmount = getStat(Stats::Attack) * damageMultiplier;

    std::cout << BOLD(FGRN(<< getName() <<)) " " << FCYN(<< DamageTypeStrings[static_cast<int>(getDamageType())] <<) << " attacks " << BOLD(FGRN(<< target.getName() <<)) << " for "
              << BOLD(FRED(<< damageAmount <<)) " damage";
    if (damageMultiplier == 1)
    {
        std::cout << std::endl;
    }
    else if (damageMultiplier > 1)
    {
        std::cout << ", " << BOLD(FRED("critical hit")) << "!" << std::endl;
    }
    else if (damageMultiplier < 1)
    {
        std::cout << ", " << FBLU("ineffective") << "!" << std::endl;
    }

    target.ReceiveDamage(getDamageType(), damageAmount, *this, true);

    return true;
}

void Creature::ReceiveDamage(DamageType type, float amount, Creature& attacker, bool canCounter)
{
    if (isAlive() == false)
    {
        throw CreatureException("Dead unit cannot receive damage");
    }

    float damageMitigatedByArmor = getStat(Stats::Armor) * ArmorTypeMultiplier[static_cast<int>(getStat(Stats::ArmorType))];
    float damageReceived = amount - damageMitigatedByArmor;

    if (damageReceived > 0)
    {
        setStat(Stats::Health, getStat(Stats::Health) - damageReceived);

        std::cout << BOLD(FGRN(<< getName() <<)) " receives " << BOLD(FRED(<< damageReceived <<)) " damage (" << BOLD(FBLU(<< damageMitigatedByArmor <<)) << " blocked by "
                  << BOLD(FCYN(<< ArmorTypeStrings[static_cast<int>(getStat(Stats::ArmorType))] <<)) ") from " << BOLD(FGRN(<< attacker.getName() <<)) << std::endl;
    }
    else
    {
        std::cout << BOLD(FGRN(<< getName() <<)) " receives no damage from " << BOLD(FGRN(<< attacker.getName() <<)) << " (" << BOLD(FBLU(<< amount <<)) << " blocked by "
                  << BOLD(FCYN(<< ArmorTypeStrings[static_cast<int>(getStat(Stats::ArmorType))] <<)) ")" << std::endl;
    }

    if (getStat(Stats::Health) <= 0)
    {
        std::cout << BOLD(FGRN(<< getName() <<)) << " " << BOLD(FRED("died")) << "!" << std::endl;
        setStat(Stats::Health, 0);
    }

    if (attacker.CanBeCounterattacked() && canCounter && isAlive())
    {
        float chance = static_cast<float>((rand() % 100) / 100.);
        if (chance < ChanceToCounterattack)
        {
            std::cout << BOLD(FGRN(<< getName() <<)) << " counterattacks " << BOLD(FGRN(<< attacker.getName() <<))
                      << " for " << BOLD(FRED(<< (getStat(Stats::Attack) / CounterattackDamageDivider) <<)) << " damage" << std::endl;
            Counterattack(attacker);
        }
    }
}

bool Creature::Counterattack(Creature& target)
{
    target.ReceiveDamage(getDamageType(), getStat(Stats::Attack) / CounterattackDamageDivider, *this, false);

    return true;
}

std::ostream& operator<<(std::ostream& stream, Creature& object)
{
    stream << BOLD(FBLU(<< object.getClassName() <<)) " " << BOLD(FGRN(<< object.getName() <<));
    for (unsigned int i = 0; i < Creature::StatsCount; i++)
    {
        if (Creature::StatDisplayByValue[i])
        {
            stream << ", " << Creature::StatsStrings[i] << ": " << object.getStats()[i].value;
        }
        else
        {
            stream << ", " << Creature::StatsStrings[i] << ": " << object.getStats()[i].name;
        }
    }

    return stream;
}

CreatureException::CreatureException(const char* str) : std::logic_error(str) {}