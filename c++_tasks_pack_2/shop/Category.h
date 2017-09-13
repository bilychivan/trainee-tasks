#ifndef CATEGORY_H
#define CATEGORY_H

#include "Stats.h"

class Item;

class Category : public Stats
{
    const static std::string Serial;
    static int globalId;
    static std::map<int, Category*> categoryList;
    std::map<int, Item*> itemList;

public:
    Category(std::string name);
    ~Category();

    const std::string &getSerial() const;
    std::map<int, Category*> &getCategoryList();
    std::map<int, Item *> &getItemList();

    void addItem(Item *item);
    void removeItem(Item *item);
};

std::ostream& operator<<(std::ostream& os, Category *obj);

#endif //CATEGORY_H
