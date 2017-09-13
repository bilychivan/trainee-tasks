#include "Customer.h"
#include "Order.h"

const std::string Customer::Serial = "CUS";
int Customer::globalId = 1;
std::map<int, Customer*> Customer::customerList;

Customer::Customer(std::string name) : Stats(globalId++, name, "Unknown")
{
    customerList[this->id] = this;
}

Customer::~Customer()
{
    for (auto& it : orderList)
    {
        delete it.second;
    }

    std::cout << "----ID:" << Serial << std::setfill(FILL_PADDING_OF_ID)
              << std::setw(WIDTH_OF_ID) << getId() << " was deleted" << std::endl;
}

const std::string &Customer::getSerial() const
{
    return this->Serial;
}

std::map<int, Customer*> &Customer::getCustomerList() const
{
    return customerList;
}

void Customer::addNewOrder(Order *newOrder)
{
    orderList[newOrder->getId()] = newOrder;
}

void Customer::removeOrder(Order *order)
{
    int it = order->getId();

    orderList.erase(it);
    delete order;
}