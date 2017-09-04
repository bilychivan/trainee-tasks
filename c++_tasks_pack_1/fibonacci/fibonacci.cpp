#include "fibonacci.h"

#define PRECEDING_ONE 1
#define PRECEDING_TWO 2

Fibonacci::Fibonacci(const int nMin, const int size)
{
    int fibonacciArrayDigits[size];

    if (size < 0)
    {
        throw FibonacciException("Exc: wrong size");
    }

    min = nMin;
    max = min + size - PRECEDING_ONE;
    index = nMin;
    precedingOne = fibonacciCalculation(min - PRECEDING_ONE);
    precedingTwo = fibonacciCalculation(min - PRECEDING_TWO);
    currentNum = precedingTwo + precedingOne;
}

int Fibonacci::fibonacciCalculation(int n)
{
    int precedingOne = 1;
    int precedingTwo = 0;
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
        precedingOne += precedingTwo;
        precedingTwo = precedingOne - precedingTwo;
    }
    if (minus && n % 2 == 0)
    {
        precedingOne *= -1;
    }
    return precedingOne;
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

    precedingOne += precedingTwo;
    precedingTwo = precedingOne - precedingTwo;
    currentNum = precedingTwo + precedingOne;
    index++;
}

void Fibonacci::prev()
{
    if (first())
    {
        throw FibonacciException("Exc: out of range");
    }

    precedingTwo = precedingOne - precedingTwo;
    precedingOne = precedingOne - precedingTwo;
    currentNum = precedingTwo + precedingOne;
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