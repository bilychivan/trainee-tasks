#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <string>
#include <vector>
#include "listable.h"
#include "item.h"

class Item;

class Category : public ListableT<Category>
{
    public:
        Category(std::string argName);
        virtual ~Category();

        virtual const std::string print() const;

        const std::string& getName() const;

        void addItem(Item* itemToAdd);

        unsigned int search(Item* itemToFind);

        void removeItem(Item* item);

        const void printItems(std::ostream& stream);

    private:
        std::string name;

        std::vector<Item*> itemList;

        void removeItem(unsigned int index);
};

#endif // CATEGORY_H
