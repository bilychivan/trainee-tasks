#include <cmath>
#include "prime.h"

Prime::Prime(const int nStart,const int size) :
            startIndex(nStart), maxIndex(nStart + size), index(0), num(2)
{
    for (int i = 0; i < startIndex; i++)
    {
       next();
    }
}

bool Prime::checkPrimeNumber(int n)
{
    for (int i = 2; i <= std::sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int Prime::getIndex() const
{
    return index;
}

int Prime::searchNextPrime()
{
    int res;

    for (res = num + 1; !checkPrimeNumber(res); res++) {};

    return res;
}

int Prime::searchPrevPrime()
{
    int res;

    for (res = num - 1; !checkPrimeNumber(res); res--) {};

    return res;
}

void Prime::next()
{
    if (over())
    {
        throw PrimeException("Exc: out of range");
    }

    index++;
    num = searchNextPrime();
}

void Prime::prev()
{
    if (first())
    {
        throw PrimeException("Exc: out of range");
    }

    index--;
    num = searchPrevPrime();
}

int Prime::value()
{
    return num;
}

bool Prime::over() const
{
    return getIndex() == maxIndex;
}

bool Prime::first() const
{
    return getIndex() == startIndex;
}

int Prime::operator++()
{
    next();

    return index;
}

int Prime::operator++(int num)
{
    int res = index;

    next();

    return res;
}

int Prime::operator--()
{
    prev();

    return index;
}

int Prime::operator--(int num)
{
    int res = index;

    prev();

    return res;
}

int Prime::operator*()
{
    return value();
}

std::ostream& operator<<(std::ostream& os, Prime& prog)
{
    os << *prog;

    return os;
}