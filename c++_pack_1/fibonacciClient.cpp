#include "fibonacci.h"

void testIteration()
{
    Fibonacci prog1(-5, 10), prog2(1, 10);

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

    std::cout << "--------------------\n";
}

void testIteration2()
{
    Fibonacci prog1(-5, 10), prog2(1, 10);

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

    std::cout << "--------------------\n";
}

void test()
{
    testIteration();

    testIteration2();

    Fibonacci prog(-12, 1);

    std::cout << "value: " << prog.value() << std::endl;

    try
    {
        prog++;

        std::cout << "value: " << prog.value() << std::endl;
    }
    catch(FibonacciException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Fibonacci prog1(3, 0);
    }
    catch(FibonacciException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Fibonacci prog1(3, -5);
    }
    catch(FibonacciException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main()
{
    test();

    return 0;
}