#ifndef PASSPORT_H
#define PASSPORT_H

#include <iostream>
#include <iomanip>
#include <string>
#include "date.h"

class Passport
{
    public:
        static const unsigned int numberCounterWidth = 4;

        Passport(std::string argFirstName, std::string argLastName, Date argDate);
        Passport(std::string argFirstName, std::string argLastName, Date argDate, std::string argSeries);

        const std::string& getSeries() const;
        unsigned int getNumber() const;
        const std::string& getFirstName() const;
        const std::string& getLastName() const;
        const Date& getDate() const;

    private:
        static unsigned int numberCounter;
        static unsigned int seriesLength;
        static std::string currentSeries;
        static const char seriesMinValue = 'A';
        static const char seriesMaxValue = 'Z';
        static const unsigned int numberCounterMax = 9999;

        std::string series;
        unsigned int number;
        std::string firstName;
        std::string lastName;
        Date date;

        friend std::string receiveSeries();
};

std::ostream& operator<<(std::ostream& stream, const Passport& passport);

class PassportException : public std::out_of_range
{
public:
    PassportException(const char*);
};

#endif // PASSPORT_H