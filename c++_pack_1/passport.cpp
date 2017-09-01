#include "passport.h"

#include <cctype>

int Passport::idCounter = 0;
Passport::Series Passport::currentSeries = Passport::Series{'A', 'A'};
const Passport::Series Passport::maxSeries = Passport::Series{'Z', 'Z'};

Passport::Passport(const std::string& firstName, const std::string& lastName, const Date& date)
    : mFirstName(firstName)
    , mLastName(lastName)
    , mDate(date)
    , mSeries()
    , mID()
{
    idCounter += 1;

    if (idCounter >= ID_LIMIT)
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
            currentSeries[1] = 'A';
        }

        idCounter = 1;
    }

    mID = idCounter;
    mSeries = currentSeries;
}

Passport::Passport(const std::string& firstName, const std::string& lastName, const Date& date, const Series& series)
    : mFirstName(firstName)
    , mLastName(lastName)
    , mDate(date)
    , mSeries(series)
    , mID()
{
    idCounter += 1;

    idCounter %= ID_LIMIT;

    mID = idCounter;
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

void Passport::reset()
{
    currentSeries = Series{'A', 'A'};
    idCounter = 0;
}

std::ostream& operator<<(std::ostream& os, const Passport& passport)
{
    const Passport::Series& series = passport.getSeries();

    os << "Surname: " << passport.getLastName() << ' ' << "name: " << passport.getFirstName() << std::endl
       << "Series: " << series[0] << series[1] << std::endl
       << passport.getDate() << std::endl
       << "ID: " << passport.getNumber();

    return os;
}

PassportException::PassportException(const std::string& message)
    : std::runtime_error(message)
{

}