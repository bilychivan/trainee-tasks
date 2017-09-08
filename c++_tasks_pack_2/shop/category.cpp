#include "category.h"
#include "shopexception.h"

Category::Category(std::string argName) : ListableT(std::string("List of all categories"), this)
{
    if (argName.length() <= 0)
    {
        throw ShopException("Category has to have a valid name");
    }

    name = argName;
}

Category::~Category()
{
    std::cout << "~Category Deleting " << print() << std::endl;

    removeListable(this);
    while (itemList.size() > 0)
    {
        delete itemList[0];
    }

    std::cout << "OK ~Category" << std::endl;
}

const std::string& Category::getName() const
{
    return name;
}

const std::string Category::print() const
{
    return ("Category: " + name + " " + getIDString());
}

void Category::addItem(Item* itemToAdd)
{
    itemList.emplace_back(itemToAdd);
}

unsigned int Category::search(Item* itemToFind)
{
    unsigned int it;

    for (it = 0; it != itemList.size(); it++)
    {
        if (itemList[it] == itemToFind)
        {
            return it;
        }
    }

    return searchNotFound;
}

void Category::removeItem(unsigned int index)
{
    itemList.erase(itemList.begin() + index);
}

void Category::removeItem(Item* item)
{
    unsigned int searchResult = search(item);

    if (searchResult != searchNotFound)
    {
        removeItem(searchResult);
    }
}

const void Category::printItems(std::ostream& stream)
{
    stream << getName() << ":" << std::endl;
    for (auto it: itemList)
    {
        stream << it->print() << std::endl;
    }
}