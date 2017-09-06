#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

#include "helpers.h"
#include "teamfight.h"

static void testWarriorSkeleton()
{
    std::cout << "__testWarriorSkeleton__\n";

    std::vector<Entity::Ptr> entities;

    entities.emplace_back(new Warrior(40, 10));
    entities.emplace_back(new Skeleton(40, 10));

    displayEntities(entities);

    entitiesAttacks(entities[0], entities[1]);

    displayEntities(entities);

    entitiesAttacks(entities[1], entities[0]);

    displayEntities(entities);

    std::cout << std::endl;
}

static void testArcherMage()
{
    std::cout << "__testArcherMage__\n";

    std::vector<Entity::Ptr> entities;

    entities.emplace_back(new Archer(40, 10));
    entities.emplace_back(new Mage(40, 10));

    displayEntities(entities);

    entitiesAttacks(entities[0], entities[1]);

    displayEntities(entities);

    entitiesCastSpells(entities[1], entities[0]);

    displayEntities(entities);

    entitiesAttacks(entities[1], entities[0]);

    displayEntities(entities);

    std::cout << std::endl;
}

static void testMageWarlockVampire()
{
    std::cout << "__testMageWarlockVampire__\n";

    std::vector<Entity::Ptr> entities;

    entities.emplace_back(new Vampire(40, 10));
    entities.emplace_back(new Warlock(40, 10));
    entities.emplace_back(new Mage(40, 10));

    displayEntities(entities);

    entitiesCastSpells(entities[2], entities[0]);

    displayEntities(entities);

    entitiesAttacks(entities[1], entities[0]);

    displayEntities(entities);

    entitiesAttacks(entities[0], entities[1]);

    displayEntities(entities);

    entities[1]->setDamage(100);

    entitiesAttacks(entities[1], entities[0]);

    displayEntities(entities);

    std::cout << getName(entities[0]) << " destroyed? " << std::boolalpha << entities[0]->isDestroyed() << std::endl;

    entitiesCastSpells(entities[1], entities[0]);

    displayEntities(entities);

    std::cout << std::endl;
}

static void testHealer()
{
    std::cout << "__testHealer__\n";

    std::vector<Entity::Ptr> entities;

    entities.emplace_back(new Healer(40, 10));
    entities.emplace_back(new Skeleton(40, 10));
    entities.emplace_back(new Archer(40, 10));

    displayEntities(entities);

    entitiesAttacks(entities[2], entities[1]);

    displayEntities(entities);

    entitiesHeals(entities[0], entities[1]);

    displayEntities(entities);

    try
    {
        entitiesAttacks(entities[0], entities[2]);
    }
    catch (EntityException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl;
}

static void testTeamfightClass()
{
    std::cout << "__testTeamfightClass__\n";

    Teamfight teamfight(3u, 3u);

    teamfight.run();
}

void test()
{
    srand(time(0));

    testWarriorSkeleton();

    testArcherMage();

    testMageWarlockVampire();

    testHealer();

    testTeamfightClass();
}