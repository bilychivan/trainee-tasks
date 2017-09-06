#ifndef TEAMFIGHT_CLASS_H
#define TEAMFIGHT_CLASS_H

#include "entity.h"

#include <array>
#include <vector>

class Teamfight
{
public:
    Teamfight(unsigned int teamSize1, unsigned int teamSize2);

    void run();

private:
    enum TEAM_INDEX
    {
        FIRST = 0,
        SECOND = 1,
        COUNT
    };

    void refillTeams();

    void displayTeams() const;

    void attackEnemy(TEAM_INDEX type1, TEAM_INDEX type2);

    void eraseDestroyed(TEAM_INDEX index);

    Entity::Ptr& findAlive(TEAM_INDEX index);

    bool isAllDead(TEAM_INDEX index) const;
    bool isTeamFullOfHealers(TEAM_INDEX index) const;

    std::array<std::vector<Entity::Ptr>, COUNT> mTeams;

    const unsigned int mTeamSize1;
    const unsigned int mTeamSize2;
};

#endif