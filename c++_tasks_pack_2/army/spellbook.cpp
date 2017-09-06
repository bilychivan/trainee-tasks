#include "spellbook.h"
#include "colors.h"

Spellbook::Spellbook(Creature& owner) : owner(owner)
{
}

int Spellbook::searchSpell(Spell spellToSearch)
{
    unsigned int it;

    for (it = 0; it != spellList.size(); it++)
    {
        if (spellList[it] == spellToSearch)
        {
            return it;
        }
    }

    return -1;
}

bool Spellbook::addSpell(Spell spellToAdd)
{
    if (searchSpell(spellToAdd) != -1)
    {
        return false;
    }

    spellList.push_back(spellToAdd);

    return true;
}

bool Spellbook::removeSpell(Spell spellToRemove)
{
    int spellIndex = searchSpell(spellToRemove);
    if (spellIndex == -1)
    {
        return false;
    }

    spellList.erase(spellList.begin() + spellIndex);

    return true;
}

SpellResult Spellbook::castSpell(Spell spellToCast, Creature& target)
{
    if (searchSpell(spellToCast) == -1)
    {
        SpellResult failure;

        failure.spellSuccessful = false;

        return failure;
    }

    std::cout << BOLD(FGRN(<< owner.getName() <<)) << " casts " << BOLD(FBLU(<< SpellStrings[static_cast<int>(spellToCast)] <<)) << " on " << BOLD(FGRN(<< target.getName() <<)) << std::endl;

    return SpellHandlers[static_cast<int>(spellToCast)](owner, target);
}