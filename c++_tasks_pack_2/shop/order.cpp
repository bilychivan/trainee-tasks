#include "order.h"
#include "shopexception.h"

Order::Order(std::string argName, Customer* argOwner, Item* firstItem) : ListableT(std::string("List of all orders"), this)
{
    if (argName.length() <= 0)
    {
        throw ShopException("Order has to have a valid name");
    }

    name = argName;

    owner = argOwner;
    owner->addOrder(this);

    itemsInOrder.emplace_back(firstItem);
}

Order::~Order()
{
    std::cout << " deleting " << print() << "..." << std::endl;

    removeListable(this);
    owner->removeOrder(this);

    std::cout << " OK" << std::endl;
}

const std::string& Order::getName() const
{
    return name;
}

const std::string Order::print() const
{
    return ("Order: " + name + " " + getIDString());
}

std::vector<Item*>* Order::getList()
{
    return &itemsInOrder;
}

void Order::addItem(Item* itemToAdd)
{
    itemsInOrder.emplace_back(itemToAdd);
}

unsigned int Order::search(Item* item)
{
    unsigned int it;

    for (it = 0; it != itemsInOrder.size(); it++)
    {
        if (itemsInOrder[it] == item)
        {
            return it;
        }
    }

    return searchNotFound;
}

void Order::removeItem(unsigned int index)
{
    itemsInOrder.erase(itemsInOrder.begin() + index);
}

void Order::removeItem(Item* item)
{
    unsigned int searchResult = search(item);

    if (searchResult != searchNotFound)
    {
        removeItem(searchResult);
    }
}

const void Order::printItems(std::ostream& stream) const
{
    stream << getName() << ":" << std::endl;
    for (auto it: itemsInOrder)
    {
        stream << it->print() << std::endl;
    }
}

const Customer* Order::getOwner() const
{
    return owner;
}