#include "date.h"

#include <iostream>

void test()
{
    Date today(15, 5, 2016);

    std::cout << today << std::endl;

    std::cout << today.getDay() << ' ' << today.getMonth() << ' ' << today.getYear() << ' ' << std::endl;

    try
    {
        Date date(32, 1, 2013);
    }
    catch(DateException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Date date(0, 1, 2013);
    }
    catch(DateException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Date date(15, 13, 2013);
    }
    catch(DateException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Date date(15, 0, 2013);
    }
    catch(DateException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Date date(29, 2, 1992);

    try
    {
        Date date(29, 2, 1991);
    }
    catch(DateException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main()
{
    test();

    return 0;
}