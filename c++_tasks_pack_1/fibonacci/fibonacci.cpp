#include "fibonacci.h"

Fibonacci::Fibonacci(const int nMin, const int size)
{
    if (size < 0)
    {
        throw FibonacciException("Exc: wrong size");
    }

    min = nMin;
    max = min + size - 1;
    index = nMin;
    x = fib_n(min - 1);
    y = fib_n(min - 2);
    num = y + x;
}

int Fibonacci::fib_n(int n)
{
    int x = 1;
    int y = 0;
    bool minus = false;

    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        n *= -1;
        minus = true;
    }
    for (int i = 1; i < n; i++)
    {
        x += y;
        y = x - y;
    }
    if (minus && n % 2 == 0)
    {
        x *= -1;
    }
    return x;
}

int Fibonacci::getIndex() const
{
    return index;
}

void Fibonacci::next()
{
    if (over())
    {
        throw FibonacciException("Exc: out of range");
    }

    x += y;
    y = x - y;
    num = y + x;
    index++;
}

void Fibonacci::prev()
{
    if (first())
    {
        throw FibonacciException("Exc: out of range");
    }

    y = x - y;
    x = x - y;
    num = y + x;
    index--;
}

int Fibonacci::value()
{
    return num;
}

bool Fibonacci::over() const
{
    return getIndex() == max;
}

bool Fibonacci::first() const
{
    return getIndex() == min;
}

int Fibonacci::operator++()
{
    next();

    return index;
}

int Fibonacci::operator++(int num)
{
    int res = index;

    next();

    return res;
}

int Fibonacci::operator--()
{
    prev();

    return index;
}

int Fibonacci::operator--(int num)
{
    prev();

    return index;
}

int Fibonacci::operator*()
{
    return value();
}

std::ostream& operator<<(std::ostream& os, Fibonacci& prog)
{
    os << *prog;

    return os;
}

int main()
{
    Fibonacci prog1(1, 10);
    Fibonacci prog2(-6, 10);

    for ( ; !prog1.over() || !prog2.over(); prog1++, prog2++ )
    {
        std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;

    for ( ; !prog1.first() || !prog2.first(); prog1--, prog2-- )
    {
        std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;

    return 0;
}