#include <iostream>
#include <string>

#include "creature.h"
#include "creatureextrastats.h"
#include "warrior.h"
#include "archer.h"
#include "mage.h"
#include "necromancer.h"
#include "vampire.h"
#include "priest.h"
#include "spells.h"
#include "spellbook.h"

int main()
{
    try
    {
        Creature::initRandom();

        Warrior corpseguy("Deadbeef");
        corpseguy.setStat(Creature::Stats::MaxHealth, 10);
        corpseguy.setStat(Creature::Stats::Attack, 5);
        corpseguy.setStat(Creature::Stats::Armor, 2);

        Priest darkpriest("xXxDarkPriestxXx");
        darkpriest.setStat(Creature::Stats::MaxHealth, 25);
        darkpriest.setStat(Creature::Stats::Attack, 8);
        darkpriest.setStat(Creature::Stats::Armor, 5);
        darkpriest.setStat(Creature::Stats::Intellegence, 8);
        darkpriest.spellbook.addSpell(Spell::SummonSkeleton);

        darkpriest.spellbook.castSpell(Spell::Heal, corpseguy);

        corpseguy.ReceiveDamage(Creature::DamageType::Magic, 100, darkpriest, false);

        std::unique_ptr<Creature> summon = darkpriest.spellbook.castSpell(Spell::SummonSkeleton, corpseguy).summonedCreature;

        std::cout << corpseguy << std::endl << darkpriest << std::endl << *summon << std::endl;

        Warrior war("Warrior");
        war.setStat(Creature::Stats::MaxHealth, 10);
        war.setStat(Creature::Stats::Attack, 5);
        war.setStat(Creature::Stats::Armor, 2);

        Archer arch("Archer");
        arch.setStat(Creature::Stats::MaxHealth, 7);
        arch.setStat(Creature::Stats::Attack, 10);
        arch.setStat(Creature::Stats::Armor, 2);

        std::cout << war << std::endl << arch << std::endl;

        while (war.isAlive() && arch.isAlive())
        {
            arch.Attack(war);
            if (war.isAlive())
            {
                war.Attack(arch);
            }
        }

        Necromancer necr("Necromancer");
        necr.setStat(Creature::Stats::MaxHealth, 6);
        necr.setStat(Creature::Stats::Attack, 7);
        necr.setStat(Creature::Stats::Armor, 2);

        std::cout << necr << std::endl;

        Creature *creatureToSummon;

        if (war.isAlive() == false)
        {
            creatureToSummon = &war;
        }
        else
        {
            creatureToSummon = &arch;
        }

        std::unique_ptr<Creature> skeleton = necr.spellbook.castSpell(Spell::SummonSkeleton, *creatureToSummon).summonedCreature;

        std::cout << *skeleton << std::endl;

        Vampire vamp("Vampire");
        vamp.setStat(Creature::Stats::MaxHealth, 11);
        vamp.setStat(Creature::Stats::Attack, 7);
        vamp.setStat(Creature::Stats::Armor, 2);

        Mage vh("Hunter");
        vh.setStat(Creature::Stats::MaxHealth, 10);
        vh.setStat(Creature::Stats::Attack, 5);
        vh.setStat(Creature::Stats::Armor, 2);

        std::cout << vamp << std::endl << vh << std::endl;

        while (vamp.isAlive() && vh.isAlive())
        {
            vh.Attack(vamp);
            if (vamp.isAlive())
            {
                vamp.Attack(vh);
            }
        }

        Priest pri("Priest");
        pri.setStat(Creature::Stats::MaxHealth, 5);
        pri.setStat(Creature::Stats::Attack, 3);
        pri.setStat(Creature::Stats::Armor, 1);
        pri.setStat(Creature::Stats::Intellegence, 5);

        Warrior tank("Tank");
        tank.setStat(Creature::Stats::MaxHealth, 10);
        tank.setStat(Creature::Stats::Attack, 5);
        tank.setStat(Creature::Stats::Armor, 2);

        Skeleton boss("Boss");
        boss.setStat(Creature::Stats::MaxHealth, 80);
        boss.setStat(Creature::Stats::Attack, 7);
        boss.setStat(Creature::Stats::Armor, 5);

        std::cout << pri << std::endl << tank << std::endl << boss << std::endl;

        while (tank.isAlive() && boss.isAlive())
        {
            if (pri.isAlive())
            {
                pri.spellbook.castSpell(Spell::Heal, tank);
            }
            if (tank.isAlive())
            {
                tank.Attack(boss);
            }
            if (boss.isAlive())
            {
                boss.Attack(tank);
            }
        }
    }
    catch (CreatureException const& e)
    {
        std::cout << e.what() << std::endl;
    }
}