#include "ariProg.h"

AriProg::AriProg(int start, int step, int size)
    : mValue(start)
    , mStep(step)
    , mSize(size)
    , mIndex(1)
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
        throw AriProgException("next() exception");
    }

    mIndex += 1;
    mValue += mStep;
}

void AriProg::prev()
{
    if (first())
    {
        throw AriProgException("prev() exception");
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

int& AriProg::operator++()
{
    mIndex += 1;
    mValue += mStep;

    return mValue;
}

int AriProg::operator++(int)
{
    int temp = mValue;

    mIndex += 1;
    mValue += mStep;

    return temp;
}

int& AriProg::operator--()
{
    mIndex -= 1;
    mValue -= mStep;

    return mValue;
}

int AriProg::operator--(int)
{
    int temp = mValue;

    mIndex -= 1;
    mValue -= mStep;

    return temp;
}

int& AriProg::operator*()
{
    return mValue;
}

std::ostream& operator<<(std::ostream& out, const AriProg& sequence)
{
    std::cout << sequence.value();

    return out;
}

AriProgException::AriProgException(const char* message)
    : std::out_of_range(message)
{

}