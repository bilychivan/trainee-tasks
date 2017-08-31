#include "ariProg.h"

AriProg::AriProg(const int argFirstMember, const int argStep, const int argLength)
{
    currentMember = argFirstMember;
    step = argStep;
    length = argLength;

    index = 1;
}

int AriProg::getIndex() const
{
    return index;
}

void AriProg::next()
{
    if ((index + 1) <= length)
    {
        currentMember += step;
        index++;
    }
    else
    {
        throw AriProgException("There is no next member");
    }
}

void AriProg::prev()
{
    if (index > 1)
    {
        currentMember -= step;
        index--;
    }
    else
    {
        throw AriProgException("There is no previous member");
    }
}

int AriProg::value()
{
    if (index > length)
    {
        throw AriProgException("Unable to return value, member doesn't exist");
    }

    return currentMember;
}

bool AriProg::last() const
{
    return (index >= length);
}

bool AriProg::first() const
{
    return (index == 1);
}

int AriProg::operator++()
{
    next();

    return value();
}

int AriProg::operator++(int)
{
    int tmp(value());

    operator++();

    return tmp;
}

int AriProg::operator--()
{
    prev();

    return value();
}

int AriProg::operator--(int)
{
    int tmp(value());

    operator--();

    return tmp;
}

int AriProg::operator*()
{
    return value();
}

std::ostream& operator<<(std::ostream& stream, AriProg& object)
{
    stream << object.value();

    return stream;
}

AriProgException::AriProgException(const char* str) : std::out_of_range(str) {}

int main()
{
    try
    {
        AriProg prog1(0, 2, 5);
        AriProg prog2(0, 1, 5);

        for (; !prog1.last() || !prog2.last(); ++prog1, ++prog2)
        {
            std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
        }
        std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;

        for ( ; !prog1.first() || !prog2.first(); prog1--, prog2-- )
        {
            std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
        }
        std::cout << prog1 << " " << *prog2 << " - " << prog1.getIndex() << std::endl;
    }
    catch (AriProgException const& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}