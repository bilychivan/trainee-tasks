#include "customer.h"
#include "shopexception.h"

Customer::Customer(std::string argName) : ListableT(std::string("List of all customers"), this)
{
    if (argName.length() <= 0)
    {
        throw ShopException("Customer has to have a valid name");
    }

    name = argName;
}

Customer::~Customer()
{
    std::cout << "Deleting " << print() << std::endl;

    removeListable(this);

    while (orderList.size() > 0)
    {
        delete orderList[0];
    }
}

const std::string& Customer::getName() const
{
    return name;
}

const std::string Customer::print() const
{
    return ("Customer: " + name + " " + getIDString());
}

const std::vector<Order*>& Customer::getList()
{
    return orderList;
}

unsigned int Customer::search(Order* order)
{
    unsigned int it;

    for (it = 0; it != orderList.size(); it++)
    {
        if (orderList[it] == order)
        {
            return it;
        }
    }

    return searchNotFound;
}

void Customer::addOrder(Order* orderToAdd)
{
    orderList.emplace_back(orderToAdd);
}

void Customer::removeOrder(unsigned int index)
{
    Order* tmp = orderList[index];

    orderList.erase(orderList.begin() + index);

    if (tmp->beingDeleted() == false)
    {
        delete tmp;
    }
}

void Customer::removeOrder(Order* order)
{
    unsigned int searchResult = search(order);

    if (searchResult != searchNotFound)
    {
        std::cout << "Deleting order from customer: " << order->getName() << std::endl;

        removeOrder(searchResult);
    }
}

const void Customer::printItems(std::ostream& stream) const
{
    stream << getName() << ":" << std::endl;
    for (auto it: orderList)
    {
        stream << it->print() << std::endl;
    }
}