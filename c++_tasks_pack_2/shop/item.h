#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>
#include "category.h"
#include "listable.h"

class Category;

class Item : public ListableT<Item>
{
    public:
        Item(std::string argName, Category* category);
        virtual ~Item();

        virtual const std::string print() const;

        const std::string& getName() const;

        void setCategory(Category* argCategory);

        const std::string& getCategoryName() const;

        void printOrders() const;

    private:
        std::string name;

        Category* category;

        bool orderLock;
};

#endif // ITEM_H
