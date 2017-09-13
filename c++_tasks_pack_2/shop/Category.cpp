#include "Category.h"
#include "Item.h"

const std::string Category::Serial = "CAT";
int Category::globalId = 1;
std::map<int, Category*> Category::categoryList;

Category::Category(std::string name) : Stats(globalId++, name, "Unknown")
{
    categoryList[this->id] = this;
}

Category::~Category()
{
    for (auto& it : itemList)
    {
        delete it.second;

        std::cout << "----ID:" << Serial << std::setfill(FILL_PADDING_OF_ID) << std::setw(WIDTH_OF_ID) << getId()
                  << " was deleted" << std::endl;
    }
}

void Category::addItem(Item *item)
{
    itemList[item->getId()] = item;
}

void Category::removeItem(Item *item)
{
    int it = item->getId();

    itemList.erase(it);
    if (itemList.empty())
    {
        delete this;
    }
}

const std::string &Category::getSerial() const
{
    return this->Serial;
}

std::map<int ,Category*> &Category::getCategoryList()
{
    return this->categoryList;
}

std::map<int, Item *> &Category::getItemList()
{
    return this->itemList;
}

std::ostream& operator<<(std::ostream& os, Category *obj)
{
    os << obj->getName() << " ID: " << obj->getSerial() << std::setfill(FILL_PADDING_OF_ID)
       << std::setw(WIDTH_OF_ID) << obj->getId()
       << " Q-ty of items: " << obj->getItemList().size();

    return os;
}