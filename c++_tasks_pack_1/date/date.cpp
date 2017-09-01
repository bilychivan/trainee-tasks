#include "date.h"

using namespace std;

Date::Date(int inputDay, int inputMonth, int inputYear)
{
    checkDate(inputDay, inputMonth, inputYear);

    day = inputDay;
    month = inputMonth;
    year = inputYear;
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

bool Date::checkDay(int inputDay, int inputMonth, int inputYear)
{
    if (inputDay < 1 || inputDay > maxDays[inputMonth - 1])
    {
        return false;
    }

    if (inputMonth == FEBRUARY && inputDay == LEAPDAY)
    {
        return ((!(inputYear % LEAPYEAR) && (inputYear % NOTLEAPYEAR)) || (!(inputYear % LEAPYEAROLD)));
    }

    return true;
}

void Date::checkDate(int inputDay, int inputMonth, int inputYear)
{
    if (inputMonth < JANUARY || inputMonth > DECEMBER)
    {
        throw DateException("Exc: wrong");
    }
    if (!checkDay(inputDay, inputMonth, inputYear))
    {
        throw DateException("Exc: wrong");
    }
}

std::ostream& operator<<(std::ostream& os, Date& date)
{
    os << date.getDay() << ' ' << date.getMonths() << ' ' << date.getYear();

    return os;
}

const int Date::maxDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    Date today(15, 5, 2016);
    Date happybirthday(17, 1, 1989);
    Date blackDay(29, 2, 1600);

    cout << today << endl << happybirthday << endl << blackDay << endl;

    try {
        Date date(99, 8, 2013);
    } catch (DateException obj) {
        cout << obj.what() << endl;
    }
    try {
        Date date(29, 99, 2013);
    } catch (DateException obj) {
        cout << obj.what() << endl;
    }
    try {
        Date date(29, 8, 0);
    } catch (DateException obj) {
        cout << obj.what() << endl;
    }
    try {
        Date date(29, 2, 1700);
    } catch (DateException obj) {
        cout << obj.what() << endl;
    }
    try {
        Date date(29, 2, 1900);
    } catch (DateException obj) {
        cout << obj.what() << endl;
    }

    return 0;
}