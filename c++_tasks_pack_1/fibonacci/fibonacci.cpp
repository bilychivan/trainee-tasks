#include "fibonacci.h"

#define PREV_POS 1
#define PREV_PREV_POS 2

Fibonacci::Fibonacci(const int nMin, const int size)
{
    int fibonacciArrayDigits[size];

    if (size < 0)
    {
        throw FibonacciException("Exc: wrong size");
    }

    min = nMin;
    max = min + size - PREV_POS;
    index = nMin;
    prevNum = fibonacciCalculation(min - PREV_POS);
    prevPrevNum = fibonacciCalculation(min - PREV_PREV_POS);
    currentNum = prevPrevNum + prevNum;
}

int Fibonacci::fibonacciCalculation(int n)
{
    int prevNum = 1;
    int prevPrevNum = 0;
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
        prevNum += prevPrevNum;
        prevPrevNum = prevNum - prevPrevNum;
    }
    if (minus && n % 2 == 0)
    {
        prevNum *= -1;
    }
    return prevNum;
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

    prevNum += prevPrevNum;
    prevPrevNum = prevNum - prevPrevNum;
    currentNum = prevPrevNum + prevNum;
    index++;
}

void Fibonacci::prev()
{
    if (first())
    {
        throw FibonacciException("Exc: out of range");
    }

    prevPrevNum = prevNum - prevPrevNum;
    prevNum = prevNum - prevPrevNum;
    currentNum = prevPrevNum + prevNum;
    index--;
}

int Fibonacci::value()
{
    return currentNum;
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

int Fibonacci::operator++(int currentNum)
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

int Fibonacci::operator--(int currentNum)
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