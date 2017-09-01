#include "passport.h"

unsigned int Passport::numberCounter = 0;
unsigned int Passport::seriesLength = 2;
std::string Passport::currentSeries = "AA";

PassportException::PassportException(const char* str) : std::out_of_range(str) {}

std::string receiveSeries()
{
    if (Passport::numberCounter > Passport::numberCounterMax)
    {
        Passport::numberCounter = 0;
        Passport::currentSeries[Passport::seriesLength - 1]++;

        for (int i = Passport::seriesLength - 1; i >= 0; i--)
        {
            if (Passport::currentSeries[i] > Passport::seriesMaxValue)
            {
                Passport::currentSeries[i] = Passport::seriesMinValue;
                if ((i - 1) >= 0)
                {
                    Passport::currentSeries[i - 1]++;
                }
                else
                {
                    throw PassportException("Ran out of series");
                }
            }
        }
    }

    return Passport::currentSeries;
}

Passport::Passport(std::string argFirstName, std::string argLastName, Date argDate) : firstName(argFirstName), lastName(argLastName), date(argDate)
{
    if (firstName.length() <= 0)
    {
        throw PassportException("First name is empty");
    }

    if (lastName.length() <= 0)
    {
        throw PassportException("Last name is empty");
    }

    series = receiveSeries();

    number = numberCounter++;
}

Passport::Passport(std::string argFirstName, std::string argLastName, Date argDate, std::string argSeries) : firstName(argFirstName), lastName(argLastName), date(argDate)
{
    if (firstName.length() <= 0)
    {
        throw PassportException("First name is empty");
    }

    if (lastName.length() <= 0)
    {
        throw PassportException("Last name is empty");
    }

    series = argSeries;

    if (series.length() != seriesLength)
    {
        throw PassportException("Invalid series length");
    }

    if (numberCounter > numberCounterMax)
    {
        numberCounter = 0;
    }
    number = numberCounter++;
}

const std::string& Passport::getSeries() const
{
    return series;
}

unsigned int Passport::getNumber() const
{
    return number;
}

const std::string& Passport::getFirstName() const
{
    return firstName;
}

const std::string& Passport::getLastName() const
{
    return lastName;
}

const Date& Passport::getDate() const
{
    return date;
}

std::ostream& operator<<(std::ostream& stream, const Passport& passport)
{
    stream << "Name: " << passport.getFirstName() << " " << passport.getLastName()
           << ", passport No.: " << passport.getSeries() << std::setfill('0') << std::setw(Passport::numberCounterWidth) << passport.getNumber() << ", date of issue: " << passport.getDate();

    return stream;
}

int main()
{
    try
    {
        Passport pass1("Mike", "Hard", Date(4, Date::Month::September, 1984));
        Passport pass2("Bob", "Joy", Date(17, Date::Month::March, 1843), "AB");

        std::cout << pass1 << std::endl;
        std::cout << pass2 << std::endl;

        for (int i = 1; ; i++)
        {
            Passport pass("Vaciliy", "Pupkin", Date(1 + (i % 25), (Date::Month)(1 + (i % 12)), i));

            std::cout << pass << std::endl;
        }
    }
    catch (PassportException const& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}