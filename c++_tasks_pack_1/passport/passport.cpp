#include "passport.h"

Passport::Passport(std::string inputFirstName, std::string inputLastName, Date inputDate) :
                    firstName(inputFirstName), lastName(inputLastName), date(inputDate)
{
    setNumber();
    series.push_back(firstLetter);
    series.push_back(secondLetter);
}

Passport::Passport(std::string inputFirstName, std::string inputLastName, Date inputDate, std::string inputSeries) :
                    firstName(inputFirstName), lastName(inputLastName), date(inputDate), series(inputSeries)
{
    setNumber();
}

void Passport::setNumber()
{
    if (globalNumber < TOTAL_NUMBERS)
    {
        globalNumber += 1;
        number = globalNumber;

        return;
    }
    if (secondLetter < 'Z')
    {
        secondLetter += 1;
        globalNumber = 1;
        number = globalNumber;

        return;
    }
    if (firstLetter < 'Z')
    {
        secondLetter = 'A';
        firstLetter += 1;
        globalNumber = 1;
        number = globalNumber;

        return;
    }
    throw PassportException("Free passport values are over");
}

const std::string& Passport::getSeries() const
{
    return series;
}

int Passport::getNumber() const
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

std::ostream& operator<<(std::ostream& os, const Passport& passport)
{
    os << passport.getSeries() << std::setfill('0') << std::setw(6) << passport.getNumber() << ' ' << passport.getFirstName() << ' ' << passport.getLastName() << " Date of receiving:"
       << passport.getDate().getDay() << ' ' << passport.getDate().getMonths() << ' ' << passport.getDate().getYear();

    return os;
}

char Passport::firstLetter = 'A';
char Passport::secondLetter = 'A';
int Passport::globalNumber = 0;