#include "date.h"

const int Date::DaysInMonth[] =
{
    31, // January
    28, // February (28 days in a common year and 29 days in leap years)
    31, // March
    30, // April
    31, // May
    30, // June
    31, // July
    31, // August
    30, // September
    31, // October
    30, // November
    31  // December
};

const char *Date::MonthStrings[] =
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

static bool isLeapYear(int year)
{
    return ((year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0));
}

Date::Date(const int argDay, const Month argMonth, const int argYear)
{
    int maxDay;

    if (argYear == 0)
    {
        throw DateException("Year can't be equal to zero");
    }

    if ((argMonth < Month::January) || (argMonth > Month::December))
    {
        throw DateException("Invalid month number given");
    }

    if (argDay < 1)
    {
        throw DateException("Day can't be less than a one");
    }

    maxDay = DaysInMonth[(int)argMonth - 1];
    if ((argMonth == Month::February) && (isLeapYear(argYear)))
    {
        maxDay++;
    }

    if (argDay > maxDay)
    {
        throw DateException("Day value overflow");
    }

    day = argDay;
    month = argMonth;
    year = argYear;
}

int Date::getDay() const
{
    return day;
}

Date::Month Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}

std::ostream& operator<<(std::ostream& stream, const Date& object)
{
    std::cout << object.getDay() << " " << Date::MonthStrings[(int)object.getMonth() - 1] << " " << object.getYear();

    return stream;
}

DateException::DateException(const char* str) : std::out_of_range(str) {}