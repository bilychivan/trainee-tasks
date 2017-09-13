#include <iostream>

#include "Category.h"
#include "Item.h"
#include "Customer.h"
#include "Order.h"

#define DELIMITER std::cout << "---------------------------" << std::endl;

void testShop()
{
    Category *cat1 = new Category("Phones");
    Category *cat2 = new Category("Laptops");

    std::cout << cat1 << std::endl;

    Item *item1 = new Item(cat1, "Apple", "4 Cores, Retina Display", 200);
    Item *item2 = new Item(cat1, "Apple2", "5 Cores, Retina Display", 200);
    Item *item3 = new Item(cat1, "Apple3", "6 Cores, Retina Display", 200);

    Item *item4 = new Item(cat2, "HP", "4 Cores, Retina Display", 200);
    Item *item5 = new Item(cat2, "HP2", "5 Cores, Retina Display", 200);
    Item *item6 = new Item(cat2, "HP3", "6 Cores, Retina Display", 200);

    item1->getId();
    item2->setCategory(cat2);
    std::cout << item2->getCategory() << std::endl;
    std::cout << item1 << std::endl;

    DELIMITER

    Customer *cus1 = new Customer("Vasiliy");
    Order *order1 = new Order(cus1, item1);
    Order *order2 = new Order(cus1, item1);

    std::map<int, Item *> orderList = order1->getItemList();

    for (std::map<int, Item *>::iterator it = orderList.begin(); it != orderList.end(); ++it)
        std::cout << it->second << std::endl;

    delete cat1;
    delete cat2;
    delete cus1;
}

int main()
{
    try
    {
        testShop();
    }
    catch(ShopException obj)
    {
        std::cout << obj.what() << std::endl;
    }

    return 0;
}