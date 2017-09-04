#include "passport.h"

Passport::Passport(std::string firstName, std::string lastName, Date date) :
                    nFirstName(firstName) , nLastName(lastName) , nDate(date)
{
    setNumber();
    nSeries.push_back(firstLet);
    nSeries.push_back(secondLet);
}

Passport::Passport(std::string firstName, std::string lastName, Date date, std::string series) :
                    nFirstName(firstName) , nLastName(lastName) , nDate(date) , nSeries(series)
{
    setNumber();
}

void Passport::setNumber()
{
    if (number < 1000000)
    {
        number += 1;
        nNumber = number;

        return;
    }
    if (secondLet < 'Z')
    {
        secondLet += 1;
        number = 1;
        nNumber = number;

        return;
    }
    if (firstLet < 'Z')
    {
        secondLet = 'A';
        firstLet += 1;
        number = 1;
        nNumber = number;

        return;
    }
    throw PassportException("Free passport values are over");
}

const std::string& Passport::getSeries() const
{
    return nSeries;
}

int Passport::getNumber() const
{
    return nNumber;
}

const std::string& Passport::getFirstName() const
{
    return nFirstName;
}

const std::string& Passport::getLastName() const
{
    return nLastName;
}

const Date& Passport::getDate() const
{
    return nDate;
}

std::ostream& operator<<(std::ostream& os, const Passport& passport)
{
    os << passport.getSeries() << std::setfill('0') << std::setw (6) << passport.getNumber() << ' ' << passport.getFirstName() << ' ' << passport.getLastName() << " Date of receiving:"
       << passport.getDate().getDay() << ' ' << passport.getDate().getMonths() << ' ' << passport.getDate().getYear();

    return os;
}

char Passport::firstLet = 'A';
char Passport::secondLet = 'A';
int Passport::number = 0;

int main()
{
    Date date(11, 6, 2000);

    for (int i = 0; i < 10; i++)
    {
        Passport prog1("Name", "Surname", date);
        std::cout << prog1 <<  std::endl;
    }
    Passport test = Passport("Name", "Surname", date, "ZZ");
    for (int i = 0; i < 10; i++)
    {
        Passport prog1("Name", "Surname", date);
        std::cout << prog1 <<  std::endl;
    }
    std::cout << test <<  std::endl;

    return 0;
}