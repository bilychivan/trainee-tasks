#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <stdexcept>

#define LEAPYEAR 4
#define NOTLEAPYEAR 100
#define LEAPDAY 29
#define LEAPYEAROLD 400
#define JANUARY 1
#define FEBRUARY 2
#define DECEMBER 12

class Date
{
private:
    int day;
    int month;
    int year;
static int maxDay[12];

    bool checkDay();
    void checkDate();
public:
    Date(const int day, const int month, const int year);
    int getDay() const;
    int getMonths() const;
    int getYear() const;

};

std::ostream& operator<<(std::ostream&, const Date&);

class DateException : public std::out_of_range
{
public:
    DateException(const char *error) : std::out_of_range(error) {};
};

#endif
