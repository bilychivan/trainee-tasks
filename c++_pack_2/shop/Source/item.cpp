#include "item.h"
#include "category.h"
#include "order.h"

#include <algorithm>

Item::Item(const std::string& name, Category* category)
    : Base(name), mCategory(category), mOrders()
{
    category->appendItem(this);

    std::cout << "    Item " << this << " constr\n";
} 

Item::~Item()
{
    std::cout << "    Item " << this << " destr | ";

    mCategory->removeItem(this);

    for (Order* order: mOrders)
    {
        order->removeItem(this);

        if (order->getItems().empty())
        {
            order->notify(SHOP_CLASSES::CUSTOMER);
        }
    }
}

void Item::setCategory(Category* category)
{
    mCategory->removeItem(this);

    mCategory = category;

    mCategory->appendItem(this);

    std::cout << "Item " << this << " set category: " << category << std::endl;
}

const Category* Item::getCategory() const
{
    return mCategory;
}

void Item::displayCategory() const
{
    std::cout << "Item " << this << " has category: " << mCategory << std::endl;
}

void Item::appendOrder(Order* order)
{
    if (std::find(mOrders.begin(), mOrders.end(), order) != mOrders.end())
    {
        throw ItemException("order already added: " + order->getName());
    }

    mOrders.push_back(order);
}

void Item::removeOrder(Order* order)
{
    auto it = std::find(mOrders.begin(), mOrders.end(), order);

    if (it == mOrders.end())
    {
        throw CategoryException("order doesn't present in item: " + order->getName());
    }

    mOrders.erase(it);
}

const std::list<Order*>& Item::getOrders() const
{
    return mOrders;
}

void Item::displayOrders() const
{
    std::cout << "Item " << this << " orders:\n" << mOrders;
}

ItemException::ItemException(const std::string& message)
    : BaseException(message)
{

}