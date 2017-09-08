#include "order.h"
#include "customer.h"
#include "item.h"

#include <algorithm>

Order::Order(const std::string& name, Customer* customer, Item* item)
    : Base(name), mItems(), mCustomer(customer)
{
    mItems.push_back(item);

    customer->appendOrder(this);
    item->appendOrder(this);

    std::cout << "    Order " << this << " constr\n";
}

Order::~Order()
{
    std::cout << "    Order " << this << " destr\n";
}

const Customer* Order::getCustomer() const
{
    return mCustomer;
}

void Order::displayCustomer() const
{
    std::cout << "Order " << this << " customer:\n" << "    " << mCustomer << std::endl;
}

void Order::appendItem(Item* item)
{
    if (std::find(mItems.begin(), mItems.end(), item) != mItems.end())
    {
        throw OrderException("item already added: " + item->getName());
    }

    mItems.push_back(item);
}

void Order::removeItem(Item* item)
{
    auto it = std::find(mItems.begin(), mItems.end(), item);

    if (it == mItems.end())
    {
        throw OrderException("item doesn't present in order: " + item->getName());
    }

    mItems.erase(it);
}

void Order::addItem(Item* item)
{
    appendItem(item);

    item->appendOrder(this);

    std::cout << "Adding " << item << " to Order " << this << std::endl;
}

void Order::deleteItem(Item* item)
{
    removeItem(item);

    item->removeOrder(this);

    std::cout << "Deleting " << item << " from Order " << this << std::endl;
}

void Order::displayItems() const
{
    std::cout << "Order " << this << " items:\n" << mItems;
}

const std::list<Item*>& Order::getItems() const
{
    return mItems;
}

void Order::notify(SHOP_CLASSES::TYPE type)
{
    if (type == SHOP_CLASSES::CUSTOMER)
    {
        mCustomer->removeOrder(this);
    }
    else if (type == SHOP_CLASSES::ITEM)
    {
        for (Item* item : mItems)
        {
            item->removeOrder(this);
        }
    }
    else
    {
        throw OrderException("this class is not allowed to delete orders");
    }

    delete this;
}

OrderException::OrderException(const std::string& message)
    : BaseException(message)
{

}