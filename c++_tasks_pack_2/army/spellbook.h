#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <vector>
#include "spells.h"
#include "creature.h"

class Spellbook
{
    public:
        Spellbook(Creature& owner);

        int searchSpell(Spell spellToSearch);
        bool addSpell(Spell spellToAdd);
        bool removeSpell(Spell spellToRemove);
        SpellResult castSpell(Spell spellToCast, Creature& target);

    private:
        std::vector<Spell> spellList;

        Creature& owner;
};

#endif // SPELLBOOK_H
