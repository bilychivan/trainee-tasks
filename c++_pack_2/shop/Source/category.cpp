#include "category.h"
#include "item.h"

#include <algorithm>

Category::Category(const std::string& name)
    : Base(name), mItems()
{
    std::cout << "    Category " << this << " constr\n";
}

Category::~Category()
{
    std::cout << "    Category " << this << " destr | ";

    for (; !mItems.empty(); )
    {
        delete mItems.back();
    }
}

void Category::appendItem(Item* item)
{
    if (std::find(mItems.begin(), mItems.end(), item) != mItems.end())
    {
        throw CategoryException("item already added: " + item->getName());
    }

    mItems.push_back(item);
}

void Category::removeItem(Item* item)
{
    auto it = std::find(mItems.begin(), mItems.end(), item);

    if (it == mItems.end())
    {
        throw CategoryException("item doesn't present in category: " + item->getName());
    }

    mItems.erase(it);
}

void Category::deleteItem(Item* item)
{
    std::cout << "Deleting item " << item << ":\n";

    delete item;
}

const std::list<Item*>& Category::getItems() const
{
    return mItems;
}

void Category::displayItems() const
{
    std::cout << "Category " << this << " items:\n" << mItems;
}

CategoryException::CategoryException(const std::string& message)
    : BaseException(message)
{

}