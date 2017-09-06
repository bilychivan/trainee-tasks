#include "teamfight.h"
#include "helpers.h"

#include <algorithm>

Teamfight::Teamfight(unsigned int teamSize1, unsigned int teamSize2)
    : mTeams(), mTeamSize1(teamSize1), mTeamSize2(teamSize2)
{
    refillTeams();
}

void Teamfight::run()
{
    unsigned long long i;

    displayTeams();

    for (i = 1ll; !(isAllDead(FIRST) || isAllDead(SECOND)) && !(isTeamFullOfHealers(FIRST) && isTeamFullOfHealers(SECOND)); i++)
    {
        std::cout << "    Step #" << i << ":\n";

        attackEnemy(FIRST, SECOND);

        displayTeams();

        if (isAllDead(FIRST) || isAllDead(SECOND))
        {
            break;
        }

        attackEnemy(SECOND, FIRST);

        displayTeams();
    }

    std::cout << i << " steps were needed to finish fighting\n";

    if (isTeamFullOfHealers(FIRST) && isTeamFullOfHealers(SECOND))
    {
        std::cout << "DRAW: only healers survived\n";
    }
    else if (isAllDead(FIRST) && isAllDead(SECOND))
    {
        std::cout << "DRAW: all entities are dead\n";
    }
    else if (isAllDead(SECOND))
    {
        std::cout << "Team #1 won\n";
    }
    else
    {
        std::cout << "Team #2 won\n";
    }
}

void Teamfight::refillTeams()
{
    for (int i = 0; i < mTeamSize1; ++i)
    {
        mTeams[FIRST].emplace_back(getEntity(getRandomGategory(), 40, 10));
    }

    for (int i = 0; i < mTeamSize2; ++i)
    {
        mTeams[SECOND].emplace_back(getEntity(getRandomGategory(), 40, 10));
    }
}

void Teamfight::displayTeams() const
{
    std::cout << "team1:\n";

    for (const auto& entity : mTeams[FIRST])
    {
        std::cout << "    " << getName(entity) << "_hp: " << entity->getHitpoints() << std::endl;
    }

    std::cout << "team2:\n";

    for (const auto& entity : mTeams[SECOND])
    {
        std::cout << "    " << getName(entity) << "_hp: " << entity->getHitpoints() << std::endl;
    }
}

Entity::Ptr& Teamfight::findAlive(TEAM_INDEX index)
{
    auto& entities = mTeams[index];

    auto it = std::find_if(entities.begin(), entities.end(), [](const Entity::Ptr& entity)
    {
        return !entity->isDestroyed();
    });

    if (it == entities.end())
    {
        throw std::runtime_error("there aren't alive entity");
    }

    return *it;
}

void Teamfight::eraseDestroyed(TEAM_INDEX index)
{
    auto& entities = mTeams[index];

    for (auto it = entities.begin(); it != entities.end(); )
    {
        if ((*it)->isDestroyed())
        {
            it = entities.erase(it);
        }
        else
        {
            it++;
        }
    }
}

bool Teamfight::isAllDead(TEAM_INDEX index) const
{
    const auto& entities = mTeams[index];

    auto it = std::find_if(entities.begin(), entities.end(), [](const Entity::Ptr& entity)
    {
        return !entity->isDestroyed();
    });

    return it == entities.end() || entities.empty();
}

void Teamfight::attackEnemy(TEAM_INDEX index1, TEAM_INDEX index2)
{
    auto& attackers = mTeams[index1];
    auto& sufferers = mTeams[index2];
    std::vector<Entity::Ptr> spawnedEntities;

    for (auto it = attackers.begin(); it != attackers.end() && !(isAllDead(index1) || isAllDead(index2)); it++)
    {
        Entity::Ptr& attacker = *it;
        CATEGORY::ID category = attacker->getCategory();

        if (category == CATEGORY::SKELETON || category == CATEGORY::WARRIOR || category == CATEGORY::ARCHER || category == CATEGORY::VAMPIRE)
        {
            entitiesAttacks(attacker, findAlive(index2));
        }
        else if (category == CATEGORY::MAGE)
        {
            entitiesCastSpells(attacker, findAlive(index2));
        }
        else if (category == CATEGORY::WARLOCK)
        {
            auto it = std::find_if(sufferers.begin(), sufferers.end(), [](Entity::Ptr& entity)
            {
                return entity->isDestroyed();
            });

            if (it != sufferers.end())
            {
                entitiesCastSpells(attacker, *it);

                spawnedEntities.emplace_back(std::move(*it));

                sufferers.erase(it);
            }
            else
            {
                entitiesAttacks(attacker, findAlive(index2));
            }
        }
        else if (category == CATEGORY::HEALER)
        {
            entitiesHeals(attacker, findAlive(index1));
        }
    }

    eraseDestroyed(index1);
    eraseDestroyed(index2);

    for (auto& entity : spawnedEntities)
    {
        attackers.emplace_back(std::move(entity));
    }
}

bool Teamfight::isTeamFullOfHealers(TEAM_INDEX index) const
{
    if (mTeams[index].empty())
    {
        return false;
    }

    for (const auto& entity : mTeams[index])
    {
        if (!(entity->getCategory() == CATEGORY::HEALER))
        {
            return false;
        }
    }

    return true;
}