#include "spellbook.h"
#include "colors.h"


Spellbook::Spellbook(Creature& owner) : owner(owner)
{
}

Spellbook::searchResult Spellbook::searchSpell(Spell spellToSearch)
{
    for (unsigned int it = 0; it != spellList.size(); it++)
    {
        if (spellList[it] == spellToSearch)
        {
            return {true, it};
        }
    }

    return {false, 0};
}

bool Spellbook::addSpell(Spell spellToAdd)
{
    if (searchSpell(spellToAdd).found == true)
    {
        return false;
    }

    spellList.push_back(spellToAdd);

    return true;
}

bool Spellbook::removeSpell(Spell spellToRemove)
{
    searchResult spellIndex = searchSpell(spellToRemove);

    if (spellIndex.found == false)
    {
        return false;
    }

    spellList.erase(spellList.begin() + spellIndex.index);

    return true;
}

SpellResult Spellbook::castSpell(Spell spellToCast, Creature& target)
{
    if (searchSpell(spellToCast).found == false)
    {
        SpellResult failure;

        failure.spellSuccessful = false;

        return failure;
    }

    std::cout << BOLD(FGRN(<< owner.getName() <<)) << " casts " << BOLD(FBLU(<< SpellStrings[static_cast<int>(spellToCast)] <<)) << " on " << BOLD(FGRN(<< target.getName() <<)) << std::endl;

    return SpellHandlers[static_cast<int>(spellToCast)](owner, target);
}