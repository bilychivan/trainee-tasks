
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

bool Prime::primeF(int n)
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

void Prime::next()
{
	int i;

    if (over())
    {
        throw PrimeException("Exc: out of range");
    }
    for (i = num + 1; !primeF(i); i++) {};
 
    index++;
    num = i;
}

void Prime::prev()
{
    int i;

    if (first())
    {
        throw PrimeException("Exc: out of range");
    }

    for (i = num - 1; !primeF(i); i--) {};

    index--;
    num = i;
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

int main() {
    Prime prog1(0, 5);
    Prime prog2(30, 5);

    for ( ; !prog1.over() || !prog2.over(); ++prog1, ++prog2 ) {
        std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
     std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;

     for ( ; !prog1.first() || !prog2.first(); prog1--, prog2-- ) {
         std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
     }
     std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;

     try
     {
         prog1.prev();
     }
     catch (PrimeException error)
     {
          std::cout << error.what() << std::endl;
     }

    return 0;
}