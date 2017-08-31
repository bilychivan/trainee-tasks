#ifndef DATE_CLASS_H
#define DATE_CLASS_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <array>

class Date
{
public:
    enum
    {
        JANUARY = 1,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };

    Date(int day, int month, int year);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

private:
    enum
    {
        LEAP1 = 4,
        NOT_LEAP1 = 100,
        LEAP2 = 400
    };

    void checkArguments() const;
    int getDayQuantity() const;

    const int mDay;
    const int mMonth;
    const int mYear;

    static const std::array<int, DECEMBER> dayQuantity;
};

std::ostream& operator<<(std::ostream& os, const Date& date);

class DateException : public std::invalid_argument
{
public:
    explicit DateException(const std::string& message);
};

#endif // DATE_CLASS_H