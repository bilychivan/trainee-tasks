#include "passport.h"

#include <iostream>
#include <vector>

void testGettersAndOuput()
{
    std::cout << "__testGettersAndOuput()__\n";

    const Passport passport("Vasya", "Lirin", Date(7, 10, 1980), Passport::Series{'J', 'C'});

    std::cout << "    Using ostream:\n" << passport << std::endl
              << "    Using getters:\n" << passport.getFirstName() << std::endl
              << passport.getLastName() << std::endl
              << passport.getSeries() << std::endl
              << passport.getNumber() << std::endl
              << passport.getDate() << std::endl << std::endl;

    Passport::reset();
}

void testFirstConstructor()
{
    std::cout << "__testFirstConstructor()__\n";

    std::vector<Passport> passportArray;
    unsigned int counter = 0u;

    try
    {
        for ( ;  ; )
        {
            passportArray.push_back(Passport("Rick", "Lumis", Date(1, 1, 2001)));

            counter += 1u;
        }
    }
    catch (PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << counter << " different IDs can be in general\n\n";

    Passport::reset();
}

void testSecondConstructor()
{
    std::cout << "__testSecondConstructor()__\n";

    std::vector<Passport> passportArray;
    unsigned int counter = 0u;

    try
    {
        for ( ; ; )
        {
            passportArray.push_back(Passport("Will", "Bard", Date(1, 1, 2001), Passport::Series{'Z', 'Y'}));

            counter += 1u;
        }
    }
    catch (PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << counter << " different IDs can be with the same series\n\n";

    Passport::reset();
}

void testRandomConstruction()
{
    std::cout << "__testRandomConstruction()__\n";

    std::vector<Passport> passportArray;

    for (int i = 0; i < Passport::ID_LIMIT; ++i)
    {
        passportArray.push_back(Passport("Jack", "Fisher", Date(1, 1, 2001), Passport::Series{'A', 'C'}));

        std::cout << passportArray.back() << std::endl;
    }

    passportArray.push_back(Passport("Jack", "Fisher", Date(1, 1, 2001), Passport::Series{'A', 'B'}));

    std::cout << passportArray.back() << std::endl;

    try
    {
        passportArray.push_back(Passport("Jack", "Fisher", Date(1, 1, 2001), Passport::Series{'A', 'C'}));
    }
    catch (PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl << std::endl;
    }

    Passport::reset();
}

void testSeries()
{
    std::cout << "__testSeries()__\n";

    try
    {
        Passport passportArray("James", "Tibbs", Date(1, 1, 2001), Passport::Series{'2', 'C'});
    }
    catch (PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Passport passportArray("James", "Tibbs", Date(1, 1, 2001), Passport::Series{'F', '*'});
    }
    catch (PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl << std::endl;
    }
}

void testNames()
{
    std::cout << "__testNames()__\n";

    try
    {
        Passport passportArray("", "Roof", Date(1, 1, 2001));
    }
    catch (PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Passport passportArray("Collin", "", Date(1, 1, 2001));
    }
    catch (PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Passport passportArray("Coll5in", "Roof", Date(1, 1, 2001));
    }
    catch (PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Passport passportArray("Collin", "R_oof", Date(1, 1, 2001));
    }
    catch (PassportException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl << std::endl;
    }
}

void test()
{
    testGettersAndOuput();

    testFirstConstructor();

    testSecondConstructor();

    testRandomConstruction();

    testSeries();

    testNames();
}

int main()
{
    test();

    return 0;
}