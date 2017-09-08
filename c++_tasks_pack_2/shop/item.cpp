#include "item.h"
#include "shopexception.h"
#include "order.h"
#include <algorithm>
#include <vector>

Item::Item(std::string argName, Category* category) : ListableT(std::string("List of all items"), this), category(category)
{
    if (argName.length() <= 0)
    {
        throw ShopException("Item has to have a valid name");
    }

    category->addItem(this);

    name = argName;

    orderLock = false;
}

Item::~Item()
{
    std::cout << "Deleting " << print() << "...";

    removeListable(this);
    category->removeItem(this);

    if (orderLock == false)
    {
        orderLock = true;

        std::vector<Order*>* orderList = (std::vector<Order*>*)Order::getListableList();
        for (auto order: *orderList)
        {
            for (auto item: *order->getList())
            {
                std::vector<Item*>* itemsInOrder = order->getList();

                if (item == this)
                {
                    std::cout << " deleting myself from orders ";
                    itemsInOrder->erase(std::remove(itemsInOrder->begin(), itemsInOrder->end(), item), itemsInOrder->end());
                }

                if (itemsInOrder->size() == 0)
                {
                    std::cout << " orders are empty, deleting them ";
                    delete order;
                }
            }
        }

        orderLock = false;
    }

    std::cout << " OK" << std::endl;
}

const std::string& Item::getName() const
{
    return name;
}

void Item::setCategory(Category* argCategory)
{
    category->removeItem(this);

    argCategory->addItem(this);

    category = argCategory;
}

const std::string& Item::getCategoryName() const
{
    return category->getName();
}

const std::string Item::print() const
{
    return ("Item: " + name + " " + getIDString() + " from " + category->print());
}

void Item::printOrders() const
{
    std::vector<Order*>* orderList = (std::vector<Order*>*)Order::getListableList();
    for (auto order: *orderList)
    {
        for (auto item: *order->getList())
        {
            if (item == this)
            {
                std::cout << order->getName() << std::endl;
            }
        }
    }
}