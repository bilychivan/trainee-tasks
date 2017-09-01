#ifndef PASSPORT_CLASS_H
#define PASSPORT_CLASS_H

#include <iostream>
#include <string>
#include <array>
#include <map>

#include "date.h"

class Passport
{
public:
    enum
    {
        SERIES_SIZE = 2,
        ID_LIMIT = 99
    };

    using Series = std::array<char, SERIES_SIZE>;

    Passport(const std::string& firstName, const std::string& lastName, const Date& date);
    Passport(const std::string& firstName, const std::string& lastName, const Date& date, const Series& series);

    const Series& getSeries() const;
    int getNumber() const;
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const Date& getDate() const;

    static void reset(const Series& series = defaultSeries);

private:
    using EntryFolder = std::map<Series, int>;

    static void increaseSeries();

    void checkSeries(const Series& series) const;
    void checkNames(const std::string& firstName, const std::string& lastName) const;

    std::string mFirstName;
    std::string mLastName;
    const Date mDate;
    Series mSeries;
    int mID;

    const static Series maxSeries;
    const static Series defaultSeries;
    static Series currentSeries;
    static EntryFolder entries;
};

std::ostream& operator<<(std::ostream& os, const Passport& passport);

std::ostream& operator<<(std::ostream& os, const Passport::Series& series);

class PassportException : public std::runtime_error
{
public:
    explicit PassportException(const std::string& message);
};

#endif // PASSPORT_CLASS_H