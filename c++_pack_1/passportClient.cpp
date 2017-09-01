#include "passport.h"

#include <vector>

void testFirstConstructor()
{
    std::cout << "__testFirstConstructor()__\n";

    const int size = 999999999;
    std::vector<Passport> passportArray;

    try
    {
        for (int i = 0; i < size; ++i)
        {
            passportArray.push_back(Passport("SomeName", "SomeLastName", Date(1, 1, 2001)));

            std::cout << passportArray.back() << std::endl;
        }
    }
    catch(PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Passport::reset();
}

void testSecondConstructor()
{
    std::cout << "__testSecondConstructor()__\n";

    const int size = 10;
    std::vector<Passport> passportArray;

    try
    {
        for (int i = 0; i < size; ++i)
        {
            passportArray.push_back(Passport("SomeName", "SomeLastName", Date(1, 1, 2001), Passport::Series{'Z', 'Y'}));

            std::cout << passportArray.back() << std::endl;
        }
    }
    catch(PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Passport::reset();
}

void testGetters()
{
    std::cout << "__testGetters()__\n";

    Passport passport("Vasya", "Lirin", Date(7, 10, 1980), Passport::Series{'E', 'T'});

    const Passport::Series& series = passport.getSeries();

    std::cout << series[0] << series[1] << std::endl
              << passport.getNumber() << std::endl
              << passport.getFirstName() << std::endl
              << passport.getLastName() << std::endl
              << passport.getDate() << std::endl;

    Passport::reset();
}

void test()
{
    testGetters();

    testFirstConstructor();

    testSecondConstructor();

    std::cout << "end\n";
}

int main()
{
    test();

    return 0;
}