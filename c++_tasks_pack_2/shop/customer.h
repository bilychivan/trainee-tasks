#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include "listable.h"
#include "order.h"

class Order;

class Customer : public ListableT<Customer>
{
    public:
        Customer(std::string argName);
        virtual ~Customer();

        virtual const std::string print() const;

        const std::string& getName() const;

        const std::vector<Order*>& getList();

        unsigned int search(Order* order);

        void addOrder(Order* orderToAdd);

        void removeOrder(unsigned int index);

        void removeOrder(Order* order);

        const void printItems(std::ostream& stream) const;

    private:
        std::string name;

        std::vector<Order*> orderList;
};

#endif // CUSTOMER_H
