#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Stats.h"

class Order;

class Customer : public Stats
{
    static const std::string Serial;
    static int globalId;
    static std::map<int, Customer*> customerList;
    std::map<int, Order*> orderList;

public:
    Customer(std::string name);
    ~Customer();

    std::map<int, Customer*> &getCustomerList() const;
    const std::string &getSerial() const;

    void addNewOrder(Order *newOrder);
    void removeOrder(Order *order);
};

#endif //CUSTOMER_H