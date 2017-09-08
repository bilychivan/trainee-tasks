#include "test.h"
#include "category.h"
#include "item.h"
#include "order.h"
#include "customer.h"

#include <array>

void testCategoryItemRelation()
{
    std::cout << "__testCategoryItemRelation()__\n";

    Category* category{new Category("Mobile")};
    Category* category2{new Category("Photo")};

    std::array<Item*, 3> items =
    {
        new Item("Nokia", category),
        new Item("Samsung", category),
        new Item("LG", category)
    };

    category->displayItems();
    category2->displayItems();

    for (const Item* item : items)
    {
        item->displayCategory();
    }

    std::cout << category << " getter:\n" << category->getItems();

    category->deleteItem(items[0]);

    category->displayItems();

    items[1]->setCategory(category2);

    items[1]->displayCategory();

    category->displayItems();

    category2->displayItems();

    std::cout << "Deleting category " << category << ":\n";

    delete category;

    std::cout << "Deleting category " << category2 << ":\n";

    delete category2;

    Category::reset();
    Item::reset();

    std::cout << "end\n\n";
}

void testItemOrderRelation()
{
    std::cout << "__testItemOrderRelation()__\n";

    Category* category{new Category("Laptop")};

    std::array<Item*, 5> items =
    {
        new Item("Nikon", category),
        new Item("Canon", category),
        new Item("Olympus", category),
        new Item("Lenovo", category),
        new Item("Fujitsu", category)
    };

    Customer* customer{new Customer("Petro")};

    std::array<Order*, 3> orders =
    {
        new Order("Work Items", customer, items[0]),
        new Order("Gift Items", customer, items[1]),
        new Order("Travel Items", customer, items[2])
    };

    category->displayItems();

    for (const Item* item : items)
    {
        item->displayOrders();
    }
    for (const Order* order : orders)
    {
        order->displayItems();
    }

    orders[0]->addItem(items[3]);
    orders[1]->addItem(items[4]);

    for (const Item* item : items)
    {
        item->displayOrders();
    }

    for (const Order* order : orders)
    {
        order->displayItems();
    }

    orders[0]->deleteItem(items[3]);

    for (const Item* item : items)
    {
        item->displayOrders();
    }

    for (const Order* order : orders)
    {
        order->displayItems();
    }

    for (const Item* item : items)
    {
        std::cout << "Deleting item " << item << ":\n";

        delete item;
    }

    category->displayItems();

    customer->displayOrders();

    std::cout << "Deleting category " << category << ":\n";

    delete category;

    std::cout << "Deleting customer " << customer << ":\n";

    delete customer;

    Category::reset();
    Customer::reset();
    Order::reset();
    Item::reset();

    std::cout << "end\n\n";
}

void testCategoryItemOrderDeletionRelation()
{
    std::cout << "__testCategoryItemOrderDeletionRelation()__\n";

    std::array<Category*, 2> categories =
    {
        new Category("Mobile"),
        new Category("Photo")
    };

    std::array<Item*, 5> items =
    {
        new Item("Nikon", categories[1]),
        new Item("Canon", categories[0]),
        new Item("Olympus", categories[1]),
        new Item("Lenovo", categories[0]),
        new Item("Samsung", categories[0])
    };

    Customer* customer{new Customer("Victor")};

    std::array<Order*, 2> orders =
    {
        new Order("Work Items", customer, items[0]),
        new Order("Gift Items", customer, items[1])
    };

    orders[0]->addItem(items[1]);
    orders[0]->addItem(items[2]);
    orders[0]->addItem(items[3]);
    orders[1]->addItem(items[2]);
    orders[1]->addItem(items[3]);
    orders[1]->addItem(items[4]);

    for (const Category* category : categories)
    {
        category->displayItems();
    }

    for (const Item* item : items)
    {
        item->displayOrders();
    }

    for (const Order* order : orders)
    {
        order->displayItems();
    }

    for (const Category* category : categories)
    {
        std::cout << "Deleting category " << category << ":\n";

        delete category;
    }

    customer->displayOrders();

    std::cout << "Deleting customer " << customer << ":\n";

    delete customer;

    Category::reset();
    Customer::reset();
    Order::reset();
    Item::reset();

    std::cout << "end\n\n";
}

void testOrderCustomerRelation()
{
    std::cout << "__testOrderCustomerRelation()__\n";

    Category* category{new Category("Mobile")};

    std::array<Item*, 2> items =
    {
        new Item("Nokia", category),
        new Item("Samsung", category)
    };

    std::array<Customer*, 2> customers =
    {
        new Customer("Petro"),
        new Customer("Dmitry")
    };

    std::array<Order*, 4> orders =
    {
        new Order("Work Items", customers[0], items[0]),
        new Order("Gift Items", customers[0], items[0]),
        new Order("Sport Items", customers[1], items[0]),
        new Order("Wasted Items", customers[1], items[1])
    };

    category->displayItems();

    for (const Item* item : items)
    {
        item->displayOrders();
    }

    for (const Order* order : orders)
    {
        order->displayCustomer();
        order->displayItems();
    }

    for (const Customer* customer : customers)
    {
        customer->displayOrders();
    }

    for (const Customer* customer : customers)
    {
        std::cout << "Deleting customer " << customer << ":\n";

        delete customer;
    }

    for (const Item* item : items)
    {
        item->displayOrders();
    }

    for (const Item* item : items)
    {
        std::cout << "Deleting item " << item << ":\n";

        delete item;
    }

    category->displayItems();

    std::cout << "Deleting category " << category << ":\n";

    delete category;

    Category::reset();
    Customer::reset();
    Order::reset();
    Item::reset();

    std::cout << "end\n\n";
}

void testIDs()
{
    std::cout << "__testIDs()__\n";

    Category* category{new Category("Mobile")};

    std::array<Item*, 2> items =
    {
        new Item("Nokia", category),
        new Item("Samsung", category)
    };

    std::array<Customer*, 2> customers =
    {
        new Customer("Petro"),
        new Customer("Dmitry")
    };

    std::array<Order*, 4> orders =
    {
        new Order("Work Items", customers[0], items[0]),
        new Order("Gift Items", customers[0], items[0]),
        new Order("Sport Items", customers[1], items[0]),
        new Order("Wasted Items", customers[1], items[1])
    };

    category->displayID();

    for (const Item* item : items)
    {
        item->displayID();
    }

    for (const Order* order : orders)
    {
        order->displayID();
    }

    for (const Customer* customer : customers)
    {
        customer->displayID();
    }

    for (const Customer* customer : customers)
    {
        std::cout << "Deleting customer " << customer << ":\n";

        delete customer;
    }

    for (const Item* item : items)
    {
        std::cout << "Deleting item " << item << ":\n";

        delete item;
    }

    std::cout << "Deleting category " << category << ":\n";

    delete category;

    Category::reset();
    Customer::reset();
    Order::reset();
    Item::reset();

    std::cout << "end\n\n";
}

void testObjectList()
{
    Category* category{new Category("Mobile")};

    std::array<Item*, 2> items =
    {
        new Item("Nokia", category),
        new Item("Samsung", category)
    };

    Category::displayNames();
    Item::displayNames();

    std::cout << "getter:\n" << Item::getNames();

    std::cout << "Deleting category " << category << ":\n";

    delete category;

    Item::displayNames();

    std::cout << "getter:\n" << Item::getNames();
}

void test()
{
    testCategoryItemRelation();

    testItemOrderRelation();

    testCategoryItemOrderDeletionRelation();

    testOrderCustomerRelation();

    testIDs();

    testObjectList();
}