#include "passport.h"

#include <cctype>

const Passport::Series Passport::maxSeries = Passport::Series{'Z', 'Z'};
const Passport::Series Passport::defaultSeries = Series{'A', 'A'};
Passport::Series Passport::currentSeries = defaultSeries;

Passport::EntryFolder Passport::entries;

void Passport::checkSeries(const Series& series) const
{
    for (char ch: series)
    {
        if (!isupper(ch))
        {
            throw PassportException("wrong series was forwarded");
        }
    }
}

void Passport::checkNames() const
{
    if (!mFirstName.size())
    {
        throw PassportException("empty firstName was forwarded");
    }
    else if (!mLastName.size())
    {
        throw PassportException("empty lastName was forwarded");
    }

    for (char ch : mFirstName)
    {
        if (!isalpha(ch))
        {
            throw PassportException("wrong firstName was forwarded");
        }
    }

    for (char ch : mLastName)
    {
        if (!isalpha(ch))
        {
            throw PassportException("wrong lastName was forwarded");
        }
    }
}

void Passport::increaseSeries()
{
    if (currentSeries == maxSeries)
    {
        throw PassportException("series limit exceeded");
    }
    else if (currentSeries[1] != 'Z')
    {
        currentSeries[1] += 1;
    }
    else
    {
        currentSeries[0] += 1;
        currentSeries[1] = defaultSeries[1];
    }
}

Passport::Passport(const std::string& firstName, const std::string& lastName, const Date& date)
    : mFirstName(firstName)
    , mLastName(lastName)
    , mDate(date)
    , mSeries()
    , mID()
{
    checkNames();

    for ( ; entries[currentSeries] >= ID_LIMIT; increaseSeries());

    entries[currentSeries] += 1;
    mID = entries[currentSeries];
    mSeries = currentSeries;
}

Passport::Passport(const std::string& firstName, const std::string& lastName, const Date& date, const Series& series)
    : mFirstName(firstName)
    , mLastName(lastName)
    , mDate(date)
    , mSeries()
    , mID()
{
    checkNames();

    checkSeries(series);

    if (entries[series] >= ID_LIMIT)
    {
        throw PassportException("current series is filled");
    }

    entries[series] += 1;
    mID = entries[series];
    mSeries = series;
}

const Passport::Series& Passport::getSeries() const
{
    return mSeries;
}

int Passport::getNumber() const
{
    return mID;
}

const std::string& Passport::getFirstName() const
{
    return mFirstName;
}

const std::string& Passport::getLastName() const
{
    return mLastName;
}

const Date& Passport::getDate() const
{
    return mDate;
}

void Passport::reset(const Series& series)
{
    currentSeries = series;
    entries.clear();
}

std::ostream& operator<<(std::ostream& os, const Passport& passport)
{
    os << "Surname|Name: " << passport.getLastName() << ' ' << passport.getFirstName() << std::endl
       << "Series|ID:    " << passport.getSeries() << ' ' << passport.getNumber() << std::endl
       << passport.getDate();

    return os;
}

std::ostream& operator<<(std::ostream& os, const Passport::Series& series)
{
    for (char ch: series)
    {
        os << ch;
    }

    return os;
}

PassportException::PassportException(const std::string& message)
    : std::runtime_error(message)
{

}