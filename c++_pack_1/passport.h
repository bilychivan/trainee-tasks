#ifndef PASSPORT_CLASS_H
#define PASSPORT_CLASS_H

#include <iostream>
#include <string>
#include <array>

#include "date.h"

class Passport
{
public:
    enum
    {
        SERIES_SIZE = 2,
        ID_LIMIT = 10
    };

    using Series = std::array<char, SERIES_SIZE>;

    Passport(const std::string& firstName, const std::string& lastName, const Date& date);
    Passport(const std::string& firstName, const std::string& lastName, const Date& date, const Series& series);

    const Series& getSeries() const;
    int getNumber() const;
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const Date& getDate() const;

    static void reset();

private:
    const std::string mFirstName;
    const std::string mLastName;
    const Date mDate;
    Series mSeries;
    int mID;

    static int idCounter;
    static Series currentSeries;
    const static Series maxSeries;
};

std::ostream& operator<<(std::ostream& os, const Passport& passport);

class PassportException : public std::runtime_error
{
public:
    explicit PassportException(const std::string& message);
};

#endif // PASSPORT_CLASS_H