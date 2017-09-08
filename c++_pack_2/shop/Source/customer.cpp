#include "customer.h"
#include "order.h"

#include <algorithm>

Customer::Customer(const std::string& name)
    : Base(name), mOrders()
{
    std::cout << "    Customer " << this << " constr\n";
}

Customer::~Customer()
{
    std::cout << "    Customer " << this << " destr | ";

    for (Order* order : mOrders)
    {
        order->notify(SHOP_CLASSES::ITEM);
    }
}

void Customer::displayOrders() const
{
    std::cout << "Customer " << this << " orders:\n" << mOrders;
}

void Customer::appendOrder(Order* order)
{
    if (std::find(mOrders.begin(), mOrders.end(), order) != mOrders.end())
    {
        throw CustomerException("order already added: " + order->getName());
    }

    mOrders.push_back(order);
}

void Customer::removeOrder(Order* order)
{
    auto it = std::find(mOrders.begin(), mOrders.end(), order);

    if (it == mOrders.end())
    {
        throw CustomerException("order doesn't present in customer: " + order->getName());
    }

    mOrders.erase(it);
}

void Customer::deleteOrder(Order* order)
{
    removeOrder(order);

    delete order;
}

CustomerException::CustomerException(const std::string& message)
    : BaseException(message)
{

}