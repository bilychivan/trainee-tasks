#ifndef ORDER_H
#define ORDER_H

#include "Stats.h"

class Item;
class Customer;

class Order : public Stats
{
    static const std::string Serial;
    static int globalId;
    static std::map<int, Order*> orderList;
    Customer *customer;
    std::map<int, Item *> itemList;

public:
    Order(Customer *customer, Item *item);
    ~Order();

    const std::string &getSerial() const;
    Customer *getCustomer() const;
    std::map<int, Order *> &getOrderList();
    std::map<int, Item *> &getItemList();

    void addItem(Item *item);
    void removeItem(Item *item);
};

std::ostream& operator<<(std::ostream& os, Order *obj);

#endif //ORDER_H
