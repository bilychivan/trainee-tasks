#include "complex.h"

void test()
{
    Complex a(3.0, 2.0), b(1.0, 4.0), c(1.0, 1.0), d(2.0, 2.0);

    std::cout << "a: " << a << "\nb: " << b << "\nc: " << c << "\nd: " << d << std::endl;

    std::cout << "a.getRe() a.getIm(): " << a.getRe() << ' ' << a.getIm() << std::endl;

    std::cout << "a + b = " << a + b << std::endl;

    std::cout << "a - b = " << a - b << std::endl;

    std::cout << "a * b = " << a * b << std::endl;

    std::cout << "a.abs() = " << a.abs() << std::endl;

    a += c;
    b -= c;
    c *= d;

    std::cout << "a += c: " << a << std::endl;

    std::cout << "b -= c: " << b << std::endl;

    std::cout << "c *= d: " << c << std::endl;

    std::cout << "a == a: ";

    if (a == a)
    {
        std::cout << "yes\n";
    }
    else
    {
        std::cout << "no\n";
    }

    std::cout << "a == b: ";

    if (a == b)
    {
        std::cout << "yes\n";
    }
    else
    {
        std::cout << "no\n";
    }

    std::cout << "a != a: ";

    if (a != a)
    {
        std::cout << "yes\n";
    }
    else
    {
        std::cout << "no\n";
    }

    std::cout << "a != b: ";

    if (a != b)
    {
        std::cout << "yes\n";
    }
    else
    {
        std::cout << "no\n";
    }
}

int main()
{
    test();

    return 0;
}