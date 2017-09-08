#ifndef CUSTOMER_CLASS_H
#define CUSTOMER_CLASS_H

#include "base.h"

class Order;

class Customer : public Base<Customer>
{
public:
    explicit Customer(const std::string& name);
    virtual ~Customer() override;

    void appendOrder(Order* order);
    void removeOrder(Order* order);

    void deleteOrder(Order* order);

    const std::list<Order*>& getOrders() const;

    void displayOrders() const;

private:
    std::list<Order*> mOrders;
};

class CustomerException : public BaseException
{
public:
    explicit CustomerException(const std::string& message);
};

#endif