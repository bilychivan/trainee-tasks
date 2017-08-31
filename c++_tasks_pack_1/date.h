#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
    public:
        static int DaysInMonth[];

        static const char *DayStrings[];
        static const char *MonthStrings[];

        enum class DayOfTheWeek
        {
            Monday = 0,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday,
            Sunday
        };

        enum class Month
        {
            January = 1,
            February,
            March,
            April,
            May,
            June,
            July,
            August,
            September,
            October,
            November,
            December
        };

        Date(const int argDay, const Month argMonth, const int argYear);
        int getDay() const;
        Month getMonth() const;
        int getYear() const;

    private:
        int day;
        Month month;
        int year;
};

std::ostream& operator<<(std::ostream&, const Date&);

int Date::DaysInMonth[]
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

class DateException : public std::out_of_range
{
public:
    DateException(const char*);
};

#endif // DATE_H
