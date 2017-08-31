#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
    public:
        static const int DaysInMonth[];

        static const char *DayStrings[];
        static const char *MonthStrings[];

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

class DateException : public std::out_of_range
{
    public:
        DateException(const char*);
};

#endif // DATE_H
