#include "date.h"

const std::array<int, Date::DECEMBER> Date::dayQuantity
{
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

Date::Date(int day, int month, int year)
    : mDay(day), mMonth(month), mYear(year)
{
    checkArguments();
}

int Date::getDay() const
{
    return mDay;
}

int Date::getMonth() const
{
    return mMonth;
}

int Date::getYear() const
{
    return mYear;
}

void Date::checkArguments() const
{
    if (mMonth < JANUARY || mMonth > DECEMBER)
    {
        throw DateException("wrong month was forwarded: " + std::to_string(mMonth));
    }
    else if (mDay < 1 || mDay > getDayQuantity())
    {
        throw DateException("wrong day was forwarded: " + std::to_string(mDay));
    }
}

int Date::getDayQuantity() const
{
    int quantity = dayQuantity[mMonth - 1];

    if (mMonth == FEBRUARY && ((mYear % LEAP1 == 0 && mYear % NOT_LEAP1) || mYear % LEAP2 == 0))
    {
        quantity += 1;
    }

    return quantity;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << "Date: " << date.getDay() << '.' << date.getMonth() << '.' << date.getYear();

    return os;
}

DateException::DateException(const std::string& message)
    : std::invalid_argument(message)
{

}