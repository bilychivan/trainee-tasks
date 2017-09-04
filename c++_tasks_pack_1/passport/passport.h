#ifndef PASSPORT_H
#define PASSPORT_H

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "date.h"

class Passport
{
private:
    std::string nFirstName;
    std::string nLastName;
    std::string nSeries;
    Date nDate;
    int nNumber;
    static int number;
    static char firstLet;
    static char secondLet;

private:
    void setNumber();
public:
    Passport(std::string firstName, std::string lastName, Date date);
    Passport(std::string firstName, std::string lastName, Date date, std::string series);

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
