#ifndef ITEM_CLASS_H
#define ITEM_CLASS_H

#include "base.h"

class Category;
class Order;

class Item : public Base<Item>
{
public:
    Item(const std::string& name, Category* category);
    virtual ~Item() override;

    void setCategory(Category* category);
    const Category* getCategory() const;

    void displayCategory() const;

    void appendOrder(Order* order);
    void removeOrder(Order* order);

    const std::list<Order*>& getOrders() const;

    void displayOrders() const;

private:
    Category* mCategory;
    std::list<Order*> mOrders;
};

class ItemException : public BaseException
{
public:
    explicit ItemException(const std::string& message);
};

#endif