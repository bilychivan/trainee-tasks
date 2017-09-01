#include "ariProg.h"

AriProg::AriProg(const int nStartNum, const int nStep, const int nCount)
{
    num = nStartNum;
    step = nStep;
    count = nCount;
    index = 1;
}

int AriProg::getIndex() const
{
    return index;
}

void AriProg::next()
{
    if (over())
    {
        throw AriProgException("Exc: out of range");
    }

    index++;
    num += step;
}

void AriProg::prev()
{
    if (first())
    {
        throw AriProgException("Exc: out of range");
    }

    index--;
    num -= step;
}

int AriProg::value()
{
    return num;
}

bool AriProg::over() const
{
    return getIndex() == count;
}

bool AriProg::first() const
{
    return getIndex() == 1;
}

int AriProg::operator++()
{
    next();

    return index;
}

int AriProg::operator++(int num)
{
    int res = index;

    next();

    return res;
}

int AriProg::operator--()
{
    int res = index;

    prev();

    return index;
}

int AriProg::operator--(int num)
{
    prev();

    return index;
}

int AriProg::operator*()
{
    return value();
}

std::ostream& operator<<(std::ostream& os, AriProg& prog)
{
    os << *prog;

    return os;
}

int main() {
    AriProg prog1(0, 5, 10);
    AriProg prog2(30, -3, 10);

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
    catch (AriProgException error)
    {
         std::cout << error.what() << std::endl;
    }

    return 0;
}