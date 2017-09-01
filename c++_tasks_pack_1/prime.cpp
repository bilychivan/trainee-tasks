#include "prime.h"

std::vector<Prime::PrimeCachedElement> Prime::cache = {};
Prime::PrimeCacheHead Prime::cacheHead = {3, 0};

static bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    if (n <= 3)
    {
        return true;
    }

    if ((n % 2 == 0) || (n % 3 == 0))
    {
        return false;
    }

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if ((n % i) == 0 || (n % (i + 2)) == 0)
        {
           return false;
        }
    }

    return true;
}

void fillCache(const Prime *prime, unsigned int index, unsigned int value)
{
    if (index >= prime->minIndex)
    {
        unsigned int cacheIndex = index - prime->minIndex;

        if (Prime::cache[cacheIndex].available == false)
        {
            Prime::cache[cacheIndex].value = value;
            Prime::cache[cacheIndex].available = true;

            if (Prime::cacheHead.startValue < value)
            {
                Prime::cacheHead.startValue = value + 2;
                Prime::cacheHead.startIndex = index;
            }
        }
    }
}

unsigned int calculateNthPrime(const Prime *prime, unsigned int targetIndex)
{
    unsigned int current = Prime::cacheHead.startIndex;

    if (targetIndex == 0)
    {
        return 2;
    }

    for (unsigned int i = Prime::cacheHead.startValue;; i += 2)
    {
        if (isPrime(i))
        {
            current++;

            fillCache(prime, current, i);

            if (current == targetIndex)
            {
                return i;
            }
        }
    }
}

unsigned int getNthPrime(const Prime *prime, unsigned int targetIndex)
{
    unsigned int cacheIndex = targetIndex - prime->minIndex;

    if (Prime::cache[cacheIndex].available == true)
    {
        return Prime::cache[cacheIndex].value;
    }

    return calculateNthPrime(prime, targetIndex);
}

Prime::Prime(const int argFirstIndex, const int argLength)
{
    if (argFirstIndex < 0)
    {
        throw PrimeException("Negative index given");
    }

    if (argLength <= 0)
    {
        throw PrimeException("Invalid length given");
    }

    index = argFirstIndex;
    minIndex = argFirstIndex;
    maxIndex = argFirstIndex + argLength;

    Prime::PrimeCachedElement temp = {false, 0};
    cache.reserve(argLength);
    for (unsigned int i = 0; i < argLength; i++)
    {
        cache.push_back(temp);
    }
}

int Prime::getIndex() const
{
    return index;
}

void Prime::next()
{
    if (!last())
    {
        index++;
    }
    else
    {
        throw PrimeException("There is no next member");
    }
}

void Prime::prev()
{
    if (!first())
    {
        index--;
    }
    else
    {
        throw PrimeException("There is no previous member");
    }
}

int Prime::value()
{
    return getNthPrime(this, index);
}

bool Prime::last() const
{
    return (index >= maxIndex);
}

bool Prime::first() const
{
    return (index == minIndex);
}

int Prime::operator++()
{
    next();

    return value();
}

int Prime::operator++(int)
{
    int tmp(value());

    operator++();

    return tmp;
}

int Prime::operator--()
{
    prev();

    return value();
}

int Prime::operator--(int)
{
    int tmp(value());

    operator--();

    return tmp;
}

int Prime::operator*()
{
    return value();
}

std::ostream& operator<<(std::ostream& stream, Prime& object)
{
    stream << object.value();

    return stream;
}

PrimeException::PrimeException(const char* str) : std::out_of_range(str) {}

int main()
{
    try
    {
        Prime prime(10000, 50);

        for ( ; !prime.last(); ++prime)
        {
            std::cout << prime << " " << prime.getIndex() << std::endl;
        }
        std::cout << prime << " " << prime.getIndex() << std::endl;

        for ( ; !prime.first(); --prime)
        {
            std::cout << prime << " " << prime.getIndex() << std::endl;
        }
        std::cout << prime << " " << prime.getIndex() << std::endl;
    }
    catch (PrimeException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}