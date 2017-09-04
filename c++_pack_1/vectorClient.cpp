#include "vector.h"

void testIncrement()
{
    std::cout << "__testIncrement__\n";

    Vector a(6.0, 2.0), b(1.0, 5.0);

    std::cout << "a: " << a << std::endl << "b: " << b << std::endl;

    a += b;

    std::cout << "a: " << a << std::endl << std::endl;
}

void testDecrement()
{
    std::cout << "__testDecrement__\n";

    Vector a(6.0, 2.0), b(1.0, 5.0);

    std::cout << "a: " << a << std::endl << "b: " << b << std::endl;

    a -= b;

    std::cout << "a: " << a << std::endl << std::endl;
}

void testEqual()
{
    std::cout << "__testEqual__\n";

    const Vector a(6.0, 2.0), b(1.0, 5.0);

    std::cout << "a: " << a << std::endl << "b: " << b << std::endl
              << "a == b:\n";

    if (a == b)
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "no\n";
    }

    std::cout << "a == a:\n";

    if (a == a)
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "no\n";
    }

    std::cout << std::endl;
}

void testNotEqual()
{
    std::cout << "__testNotEqual__\n";

    const Vector a(6.0, 2.0), b(1.0, 5.0);

    std::cout << "a: " << a << std::endl << "b: " << b << std::endl
              << "a != b:\n";

    if (a != b)
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "no\n";
    }

    std::cout << "a != a:\n";

    if (a != a)
    {
        std::cout << "true\n";
    }
    else
    {
        std::cout << "no\n";
    }

    std::cout << std::endl;
}

void testLen()
{
    std::cout << "__testLen__\n";

    const Vector a(6.0, 2.0);

    std::cout << "length of " << a << ": " << a.length() << std::endl << std::endl;
}

void testSum()
{
    std::cout << "__testSum__\n";

    const Vector a(6.0, 2.0), b(1.0, 5.0);

    std::cout << "a: " << a << std::endl << "b: " << b << std::endl
              << "a + b = " << a + b << std::endl << std::endl;
}

void testDiff()
{
    std::cout << "__testDiff__\n";

    const Vector a(6.0, 2.0), b(1.0, 5.0);

    std::cout << "a: " << a << std::endl << "b: " << b << std::endl
              << "a - b = " << a - b << std::endl << std::endl;
}

void test()
{
    testIncrement();

    testDecrement();

    testEqual();

    testNotEqual();

    testLen();

    testSum();

    testDiff();
}

int main()
{
    test();

    return 0;
}