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
    static const int LEAP1;
    static const int NOT_LEAP1;
    static const int LEAP2;

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