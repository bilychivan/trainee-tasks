#include "fibonacci.h"

Fibonacci::Fibonacci(int index, int size)
    : mCurrent(fib(index))
    , mIndex(index)
    , mInitialIndex(index)
    , mLastIndex(mInitialIndex + size - 1)
{
    if (size < 1)
    {
        throw FibonacciException("wrong size was forwarded: " + std::to_string(size));
    }
}

int Fibonacci::getIndex() const
{
    return mIndex;
}

void Fibonacci::next()
{
    mIndex += 1;
    mCurrent = fib(mIndex);
}

void Fibonacci::prev()
{
    mIndex -= 1;
    mCurrent = fib(mIndex);
}

int Fibonacci::value() const
{
    if (mIndex < mInitialIndex || mIndex > mLastIndex)
    {
        throw FibonacciException("index out of range: " + std::to_string(mIndex));
    }

    return mCurrent;
}

bool Fibonacci::over() const
{
    return mIndex == mLastIndex;
}

bool Fibonacci::first() const
{
    return mIndex == mInitialIndex;
}

int Fibonacci::operator++()
{
    next();

    return value();
}

int Fibonacci::operator++(int)
{
    int temp = value();

    next();

    return temp;
}

int Fibonacci::operator--()
{
    prev();

    return value();
}

int Fibonacci::operator--(int)
{
    int temp = value();

    prev();

    return temp;
}

int Fibonacci::operator*()
{
    return value(); 
}

int Fibonacci::fib(int n) const
{
    if (n < 0)
    {
        if (n % 2)
        {
            return fib(-n);
        }
        else
        {
            return fib(-n) * -1;
        }
    }

    if (n < 2)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

std::ostream& operator<<(std::ostream& os, const Fibonacci& f)
{
    std::cout << f.value();

    return os;
}

FibonacciException::FibonacciException(const std::string& message)
    : std::runtime_error(message)
{

}