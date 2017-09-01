#include "date.h"

using namespace std;

Date::Date(int nDate, int nMonth, int nYear) :
           day(nDate), month(nMonth), year(nYear)
{
    checkDate();
};

int Date::getDay() const
{
    return day;
}

int Date::getMonths() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

bool Date::checkDay()
{
    if (day < 1 || day > maxDays[month - 1])
    {
        return false;
    }

    if (month == FEBRUARY && day == LEAPDAY)
    {
        return ((!(year % LEAPYEAR) && (year % NOTLEAPYEAR)) || (!(year % LEAPYEAROLD)));
    }

    return true;
}

void Date::checkDate()
{
    if (month < JANUARY || month > DECEMBER)
    {
        throw DateException("Exc: wrong");
    }
    if (!checkDay())
    {
        throw DateException("Exc: wrong");
    }
}

std::ostream& operator<<(std::ostream& os, Date& date)
{
    os << date.getDay() << ' ' << date.getMonths() << ' ' << date.getYear();

    return os;
}

int Date::maxDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};