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

const char *Date::DayStrings[] =
{
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
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

/*
    Source:
        https://stackoverflow.com/questions/3220163/how-to-find-leap-year-programatically-in-c
*/
static bool isLeapYear(int year)
{
    return ((year & 3) == 0 && ((year % 25) != 0 || (year & 15) == 0));
}

/*
    Determination of the day of the week using Gauss's algorithm

    Source:
        https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Gauss.27s_algorithm
    Explanation:
        https://stackoverflow.com/questions/6385190/correctness-of-sakamotos-algorithm-to-find-the-day-of-week/6385934#6385934
*/
static int getDayOfTheWeek(int d, Date::Month month, int y)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int m = (int)month;

    d--;
    y -= m < 3;

    return ((y + y/4 - y/100 + y/400 + t[m-1] + d) % 7);
}

Date::Date(const int argDay, const Month argMonth, const int argYear)
{
    int maxDay;

    if (argYear < 0)
    {
        throw DateException("Year can't be a negative number");
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
    std::cout << Date::DayStrings[getDayOfTheWeek(object.getDay(), object.getMonth(), object.getYear())]
              << ", " << object.getDay() << " " << Date::MonthStrings[(int)object.getMonth() - 1] << " " << object.getYear();

    return stream;
}

DateException::DateException(const char* str) : std::out_of_range(str) {}