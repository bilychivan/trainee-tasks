#include "fibonacci.h"

static void fast_fib(long long int n,long long int ans[])
{
    const int Mod = 1000000007;
    long long int a, b, c, d;

    if (n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;

        return;
    }

    fast_fib((n / 2), ans);

    a = ans[0];
    b = ans[1];
    c = 2 * b - a;

    if (c < 0)
    {
        c += Mod;
    }

    c = (a * c) % Mod;
    d = (a * a + b * b) % Mod;

    if ((n % 2) == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c + d;
    }
}

Fibonacci::Fibonacci(const int argFirstIndex, const int argLength) : index(argFirstIndex), minIndex(argFirstIndex), maxIndex(argFirstIndex + argLength)
{
}

int Fibonacci::getIndex() const
{
    return index;
}

void Fibonacci::next()
{
    if (!last())
    {
        index++;
    }
    else
    {
        throw FibonacciException("There is no next member");
    }
}

void Fibonacci::prev()
{
    if (!first())
    {
        index--;
    }
    else
    {
        throw FibonacciException("There is no previous member");
    }
}

int Fibonacci::value()
{
    long long int ans[2] = {0};

    fast_fib(index, ans);

    if ((index < 0) && ((index % 2) == 0))
    {
        ans[0] *= -1;
    }

    return ans[0];
}

bool Fibonacci::last() const
{
    return (index >= maxIndex);
}

bool Fibonacci::first() const
{
    return (index == minIndex);
}

int Fibonacci::operator++()
{
    next();

    return value();
}

int Fibonacci::operator++(int)
{
    int tmp(value());

    operator++();

    return tmp;
}

int Fibonacci::operator--()
{
    prev();

    return value();
}

int Fibonacci::operator--(int)
{
    int tmp(value());

    operator--();

    return tmp;
}

int Fibonacci::operator*()
{
    return value();
}

std::ostream& operator<<(std::ostream& stream, Fibonacci& object)
{
    stream << object.value();

    return stream;
}

FibonacciException::FibonacciException(const char* str) : std::out_of_range(str) {}

int main()
{
    try
    {
        Fibonacci prog1(-10, 10);
        Fibonacci prog2(20, 10);

        for ( ; !prog1.last() || !prog2.last(); prog1++, prog2++ ) {
            std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
        }
        std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;

        for ( ; !prog1.first() || !prog2.first(); prog1--, prog2-- ) {
            std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
        }
        std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    catch (FibonacciException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}