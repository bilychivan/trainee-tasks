#ifndef ITEMS_H
#define ITEMS_H

#include "Stats.h"

class Order;
class Category;

class Item : public Stats
{
    static const std::string Serial;
    static int globalId;
    static std::map<int, Item*> itemList;
    std::map<int, Order*> orderList;
    Category *category;
    double price;

public:
    Item(Category *category, std::string name, std::string desc, double price);
    ~Item();

    const std::string &getSerial() const;
    Category *getCategory() const;
    double getPrice() const;
    std::map<int, Item*> &getItemsList() const;

    void addToOrder(Order *order);
    void setCategory(Category *newCategory);
    void removeOrder(Order *order);
};

std::ostream& operator<<(std::ostream& os, const Item *obj);

#endif //ITEMS_H
