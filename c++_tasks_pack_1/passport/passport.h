#ifndef PASSPORT_H
#define PASSPORT_H

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "date.h"

#define TOTAL_NUMBERS 1000000

class Passport
{
private:
    std::string firstName;
    std::string lastName;
    std::string series;
    Date date;
    int number;
    static int globalNumber;
    static char firstLetter;
    static char secondLetter;

private:
    void setNumber();
public:
    Passport(std::string inputFirstName, std::string inputLastName, Date inputDate);
    Passport(std::string inputFirstName, std::string inputLastName, Date inputDate, std::string inputSeries);

    const std::string& getSeries() const;
    int getNumber() const;
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const Date& getDate() const;
};

std::ostream& operator<<(std::ostream& os, const Passport& passport);

class PassportException : public std::out_of_range
{
public:
    PassportException(const char *error) : std::out_of_range(error) {};
};

#endif // PASSPORT_H
