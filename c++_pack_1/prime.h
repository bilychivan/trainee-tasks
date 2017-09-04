#ifndef PRIME_CLASS_H
#define PRIME_CLASS_H

#include <iostream>
#include <stdexcept>
#include <map>
#include <string>

class Prime
{
public:
    Prime(int startIndex, int length);

    int getIndex() const;

    void next();
    void prev();

    int value() const;

    bool over() const;
    bool first() const;

    int operator++();
    int operator++(int);

    int operator--();
    int operator--(int);

    int operator*() const;

    static void reset();

private:
    static void calculateIndexes(int begin, int end);

    int mIndex;
    const int mInitialIndex;
    const int mLastIndex;

    static std::map<int, int> mCalculatedPrimes;
};

std::ostream& operator<<(std::ostream& os, const Prime& prime);

class PrimeException : public std::runtime_error
{
public:
    explicit PrimeException(const std::string& message);
};

bool isPrime(int n);
int calculatePrime(int index);

#endif // PRIME_CLASS_H
