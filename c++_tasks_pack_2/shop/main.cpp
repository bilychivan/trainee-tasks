#include <iostream>
#include <string>

#include "shopexception.h"
#include "item.h"
#include "category.h"
#include "listable.h"
#include "customer.h"
#include "order.h"

#define SEPARATE std::cout << "-----" << std::endl;

int main()
{
    try
    {
        Category* catStr = new Category("Strength heroes");
        Category* catAgi = new Category("Agility heroes");
        Category* catInt = new Category("Intellegence heroes");

        Item* str1 = new Item("warrior", catAgi);
        Item* str2 = new Item("paladin", catStr);
        Item* str3 = new Item("fighter", catStr);

        {
            auto str4 = std::make_shared<Item>("temp guy", catStr);
        }

        Item* agi1 = new Item("archer", catAgi);
        Item* agi2 = new Item("rogue", catAgi);
        Item* agi3 = new Item("thief", catAgi);

        Item* int1 = new Item("mage", catInt);
        Item* int2 = new Item("warlock", catInt);
        Item* int3 = new Item("necromancer", catInt);

        Customer* cus1 = new Customer("Vasil");
        Customer* cus2 = new Customer("Petro");
        Customer* cus3 = new Customer("Hlopchina");

        Order* vasilOrder = new Order("Vasil's order 1", cus1, str1);
        Order* vasilOrder2 = new Order("Vasil's order 2", cus1, agi1);
        Order* vasilOrder3 = new Order("Vasil's order 3", cus1, agi2);
        vasilOrder->addItem(str2);
        vasilOrder->addItem(int2);

        Order* petroOrder = new Order("Petro's order", cus2, int1);
        petroOrder->addItem(int2);
        petroOrder->addItem(int3);

        SEPARATE

        vasilOrder->printItems(std::cout);

        str1->setCategory(catStr);

        SEPARATE

        vasilOrder->printItems(std::cout);

        SEPARATE

        cus1->removeOrder(vasilOrder);

        SEPARATE

        std::cout << "Orders containing " << int2->print() << ":" << std::endl;
        int2->printOrders();

        SEPARATE

        std::cout << "Owner of " << petroOrder->print() << " is:" << std::endl;
        std::cout << petroOrder->getOwner()->getName() << std::endl;

        SEPARATE

        delete catStr;
        delete catAgi;
        delete catInt;

        cus1->printItems(std::cout);
        delete cus1;
        delete cus2;
        delete cus3;

        SEPARATE

        std::cout << "All customers:" << std::endl;
        Customer::printAll(std::cout);

        SEPARATE

        std::cout << "All orders:" << std::endl;
        Order::printAll(std::cout);

        SEPARATE

        std::cout << "All items:" << std::endl;
        Item::printAll(std::cout);

        SEPARATE

        std::cout << "All categories:" << std::endl;
        Category::printAll(std::cout);
    }
    catch (ShopException const& e)
    {
        std::cout << e.what() << std::endl;
    }
}