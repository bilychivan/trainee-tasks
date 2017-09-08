#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include "listable.h"
#include "customer.h"
#include "item.h"

class Customer;

class Order : public ListableT<Order>
{
    public:
        static const unsigned int searchNotFound = INT_MAX;

        Order(std::string argName, Customer* argOwner, Item* firstItem);
        virtual ~Order();

        virtual const std::string print() const;

        const std::string& getName() const;

        std::vector<Item*>* getList();

        void addItem(Item* itemToAdd);

        unsigned int search(Item* item);

        void removeItem(unsigned int index);

        void removeItem(Item* item);

        const void printItems(std::ostream& stream) const;

        const Customer* getOwner() const;

    private:
        std::string name;

        Customer* owner;

        std::vector<Item*> itemsInOrder;
};

#endif // ORDER_H
