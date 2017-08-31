#include "ariProg.h"

#include <iostream>

void testIteration()
{
    std::cout << "__testIteration1__\n";

    AriProg prog1(0, 5, 10);
    AriProg prog2(30, -3, 10);

    for ( ; !prog1.over() && !prog2.over(); ++prog1, ++prog2)
    {
        std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;

    for ( ; !prog1.first() && !prog2.first(); --prog1, --prog2)
    {
        std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    std::cout << prog1 << ' ' << *prog2 << " - " << prog1.getIndex() << std::endl;

    std::cout << "--------------------\n";
}

void testIteration2()
{
    std::cout << "__testIteration2__\n";

    AriProg prog1(0, 5, 10);
    AriProg prog2(30, -3, 10);

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

void testException()
{
    std::cout << "__testException__\n";

    AriProg prog(0, 5, 10);

    for ( ; !prog.over(); prog.next())
    {
        std::cout << prog << " - " << prog.getIndex() << std::endl;
    }
    std::cout << prog << " - " << prog.getIndex() << std::endl;

    try
    {
        prog.next();
    }
    catch(AriProgException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    for ( ; !prog.first(); prog.prev())
    {
        std::cout << prog << " - " << prog.getIndex() << std::endl;
    }
    std::cout << prog << " - " << prog.getIndex() << std::endl;

    try
    {
        prog.prev();
    }
    catch(AriProgException& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "--------------------\n";
}

void test()
{
    testIteration();

    testIteration2();

    testException();
}

int main()
{
    test();

    return 0;
}