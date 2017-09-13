#include "Item.h"
#include "Category.h"
#include "Order.h"

const std::string Item::Serial = "ITE";
int Item::globalId = 1;
std::map<int, Item*> Item::itemList;

Item::Item(Category *nCategory, std::string nName, std::string nDesc, double nPrice) : Stats(globalId++, std::move(nName), std::move(nDesc)), price(nPrice)
{
    category = nCategory;
    category->addItem(this);
    itemList[this->id] = this;
}

Item::~Item()
{
    for (auto& it : orderList)
    {
        it.second->removeItem(this);
    }
    itemList.erase(id);

    std::cout << "----ID:" << Serial << std::setfill(FILL_PADDING_OF_ID) << std::setw(WIDTH_OF_ID)
              << getId() << " was deleted" << std::endl;
}

void Item::addToOrder(Order *order)
{
    orderList[order->getId()] = order;
}

const std::string &Item::getSerial() const
{
    return this->Serial;
}

double Item::getPrice() const
{
    return this->price;
}

void Item::setCategory(Category *newCategory)
{
    if (category)
    {
        category->removeItem(this);
        newCategory->addItem(this);
    }
    category = newCategory;
}

Category *Item::getCategory() const
{
    return category;
}

void Item::removeOrder(Order *order)
{
    orderList.erase(order->getId());
}

std::map<int, Item*> &Item::getItemsList() const
{
    return itemList;
}

std::ostream& operator<<(std::ostream& os, const Item *obj)
{
    os << "ID: " << obj->getSerial() << std::setfill(FILL_PADDING_OF_ID) << std::setw(WIDTH_OF_ID) << obj->getId() << std::endl
    << "Name: " << obj->getName() << std::endl
    << "Desc: " << obj->getDesc() << std::endl
    << "Price: " << obj->getPrice();

    return os;
}