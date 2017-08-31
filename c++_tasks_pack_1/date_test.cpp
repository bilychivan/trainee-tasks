#include "date.h"

int main()
{
    Date today(15, static_cast<Date::Month>(5), 2016);
    Date happybirthday(17, static_cast<Date::Month>(1), 1989);
    Date blackDay(29, static_cast<Date::Month>(2), 1600);

    std::cout << today << std::endl << happybirthday << std::endl << blackDay << std::endl;

    try
    {
        Date date(99, static_cast<Date::Month>(8), 2013);
    }
    catch (DateException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Date date(29, static_cast<Date::Month>(99), 2013);
    }
    catch (DateException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Date date(29, static_cast<Date::Month>(8), 0);
    }
    catch (DateException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Date date(29, static_cast<Date::Month>(2), 1700);
    }
    catch (DateException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Date date(29, static_cast<Date::Month>(2), 1900);
    }
    catch (DateException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
