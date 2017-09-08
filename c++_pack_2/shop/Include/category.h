#ifndef CATEGORY_CLASS_H
#define CATEGORY_CLASS_H

#include "base.h"

class Item;

class Category : public Base<Category>
{
public:
    explicit Category(const std::string& name);
    virtual ~Category() override;

    void appendItem(Item* item);
    void removeItem(Item* item);

    void deleteItem(Item* item);

    const std::list<Item*>& getItems() const;

    void displayItems() const;

private:
    std::list<Item*> mItems;
};

class CategoryException : public BaseException
{
public:
    explicit CategoryException(const std::string& message);
};

#endif