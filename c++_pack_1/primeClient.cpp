#include "prime.h"

void testIteration()
{
    std::cout << "__testIteration()__\n";

    Prime prog1(1, 5), prog2(8, 5);

    for ( ; !prog1.over() && !prog2.over(); prog1.next(), prog2.next())
    {
        std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;

    for ( ; !prog1.first() && !prog2.first(); prog1.prev(), prog2.prev())
    {
        std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;

    Prime::reset();

    std::cout << "--------------------\n";
}

void testIteration2()
{
    std::cout << "__testIteration2()__\n";

    Prime prog1(6, 10), prog2(11, 10);

    for ( ; !prog1.over() && !prog2.over(); prog1++, prog2++)
    {
        std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;

    for ( ; !prog1.first() && !prog2.first(); prog1--, prog2--)
    {
        std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;

    Prime::reset();

    std::cout << "--------------------\n";
}

void testExceptions()
{
    std::cout << "__testExceptions()__\n";

    Prime prog(5, 1);

    std::cout << "value: " << prog.value() << std::endl;

    try
    {
        prog++;

        std::cout << "value: " << prog.value() << std::endl;
    }
    catch(PrimeException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Prime prog2(5, 1);

    std::cout << "value: " << prog2.value() << std::endl;

    try
    {
        prog2--;

        std::cout << "value: " << prog2.value() << std::endl;
    }
    catch(PrimeException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Prime prog1(3, 0);
    }
    catch(PrimeException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Prime prog1(0, 3);
    }
    catch(PrimeException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    Prime::reset();
}

void test()
{
    testIteration();

    testIteration2();

    testExceptions();
}

int main()
{
    test();

    return 0;
}