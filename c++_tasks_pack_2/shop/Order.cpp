#include "Customer.h"
#include "Item.h"
#include "Order.h"

const std::string Order::Serial = "ORD";
int Order::globalId = 1;
std::map<int, Order*> Order::orderList {};

Order::Order(Customer *customer, Item *item) : Stats(globalId++), customer(customer)
{
    itemList[item->getId()] = item;
    item->addToOrder(this);
    customer->addNewOrder(this);
    orderList[this->id] = this;
}

Order::~Order()
{
    std::map<int, Item *>::iterator it = itemList.begin();
    std::map<int, Item *>::iterator itEnd = itemList.end();

    for (; it != itEnd; it++)
    {
        it->second->removeOrder(this);
    }
    orderList.erase(id);

    std::cout << "----ID:" << Serial << std::setfill(FILL_PADDING_OF_ID)
              << std::setw(WIDTH_OF_ID) << getId() << " was deleted" << std::endl;
}

const std::string &Order::getSerial() const
{
    return this->Serial;
}

Customer *Order::getCustomer() const
{
    return this->customer;
}

std::map<int, Order *> &Order::getOrderList()
{
    return this->orderList;
}

std::map<int, Item *> &Order::getItemList()
{
    return this->itemList;
}

void Order::addItem(Item *item)
{
    itemList[item->getId()] = item;
    item->addToOrder(this);
}

void Order::removeItem(Item *item)
{
    int it = item->getId();

    itemList.erase(it);
    if (itemList.empty())
    {
        customer->removeOrder(this);
    }
}

std::ostream& operator<<(std::ostream& os, Order *obj)
{
    os << "ID: " << obj->getSerial() << std::setfill(FILL_PADDING_OF_ID) << std::setw(WIDTH_OF_ID) << obj->getId()
       << " Q-ty of items: " << obj->getItemList().size();

    return os;
}