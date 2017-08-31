#include "ariProg.h"

AriProg::AriProg(int start, int step, int size)
    : mValue(start), mStep(step), mSize(size), mIndex(1)
{

}

int AriProg::getIndex() const
{
    return mIndex;
}

void AriProg::next()
{
    if (over())
    {
        throw AriProgException("Exceeding the max index");
    }

    mIndex += 1;
    mValue += mStep;
}

void AriProg::prev()
{
    if (first())
    {
        throw AriProgException("Exceeding the min index");
    }

    mIndex -= 1;
    mValue -= mStep;
}

int AriProg::value() const
{
    return mValue;
}

bool AriProg::over() const
{
    return mIndex == mSize;
}

bool AriProg::first() const
{
    return mIndex == 1;
}

int AriProg::operator++()
{
    next();

    return value();
}

int AriProg::operator++(int)
{
    int temp = value();

    next();

    return temp;
}

int AriProg::operator--()
{
    prev();

    return value();
}

int AriProg::operator--(int)
{
    int temp = value();

    prev();

    return temp;
}

int AriProg::operator*() const
{
    return value();
}

std::ostream& operator<<(std::ostream& os, const AriProg& sequence)
{
    os << sequence.value();

    return os;
}

AriProgException::AriProgException(const std::string& message)
    : std::runtime_error(message)
{

}