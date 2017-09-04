#include "prime.h"

std::map<int, int> Prime::mCalculatedPrimes;

Prime::Prime(int index, int size)
    : mIndex(index), mInitialIndex(index), mLastIndex(index + size - 1)
{
    if (index < 1)
    {
        throw PrimeException("wrong index was forwarded: " + std::to_string(index));
    }
    else if (size < 1)
    {
        throw PrimeException("wrong size was forwarded: " + std::to_string(size));
    }

    calculateIndexes(mInitialIndex, mLastIndex);
}

int Prime::getIndex() const
{
    return mIndex;
}

void Prime::next()
{
    mIndex += 1;
}

void Prime::prev()
{
    mIndex -= 1;
}

int Prime::value() const
{
    if (mIndex < mInitialIndex || mIndex > mLastIndex)
    {
        throw PrimeException("index out of range: " + std::to_string(mIndex));
    }

    return mCalculatedPrimes[mIndex];
}

bool Prime::over() const
{
    return mIndex == mLastIndex;
}

bool Prime::first() const
{
    return mIndex == mInitialIndex;
}

int Prime::operator++()
{
    next();

    return value();
}

int Prime::operator++(int)
{
    int temp = value();

    next();

    return temp;
}

int Prime::operator--()
{
    prev();

    return value();
}

int Prime::operator--(int)
{
    int temp = value();

    prev();

    return temp;
}

int Prime::operator*() const
{
    return value();
}

void Prime::reset()
{
    mCalculatedPrimes.clear();
}

void Prime::calculateIndexes(int begin, int end)
{
    for ( ; begin <= end; ++begin)
    {
        if (mCalculatedPrimes.find(begin) == mCalculatedPrimes.end())
        {
            mCalculatedPrimes[begin] = calculatePrime(begin);
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Prime& prime)
{
    os << prime.value();

    return os;
}

PrimeException::PrimeException(const std::string& message)
    : std::runtime_error(message)
{

}

bool isPrime(int n)
{
    int max = n / 2;

    if (n == 2)
    {
        return 1;
    }
    else if (n < 2 || n % 2 == 0)
    {
        return 0;
    }

    for (int i = 3; i < max; i += 2)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int calculatePrime(int index)
{
    int quantity = 0, result = -1;

    for (int i = 1; i > 0 && quantity < index; ++i)
    {
        if (isPrime(i))
        {
            quantity++;
            result = i;
        }
    }

    return result;
}