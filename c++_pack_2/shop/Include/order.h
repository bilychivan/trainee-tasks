#ifndef ORDER_CLASS_H
#define ORDER_CLASS_H

#include "base.h"
#include "attributes.h"

class Customer;
class Item;

class Order : public Base<Order>
{
public:
    explicit Order(const std::string& name, Customer* customer, Item* item);
    virtual ~Order() override;

    const Customer* getCustomer() const;

    void displayCustomer() const;

    void appendItem(Item* item);
    void removeItem(Item* item);

    void addItem(Item*);
    void deleteItem(Item* item);

    const std::list<Item*>& getItems() const;

    void displayItems() const;

    void notify(SHOP_CLASSES::TYPE type);

private:
    std::list<Item*> mItems;
    Customer* mCustomer;
};

class OrderException : public BaseException
{
public:
    explicit OrderException(const std::string& message);
};

#endif