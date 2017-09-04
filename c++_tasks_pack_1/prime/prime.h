#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include <stdexcept>
#include <cmath>

class Prime
{
private:
    int index;
    int num;
    int startIndex;
    int maxIndex;

    bool checkPrimeNumber(int n);
    int searchNextPrime();
    int searchPrevPrime();

public:
    Prime(const int nStart, const int size);

    int getIndex() const;
    void next();
    void prev();
    int value();
    bool over() const;
    bool first() const;
    int operator++();
    int operator++(int);
    int operator--();
    int operator--(int);
    int operator*();
};

std::ostream& operator<<(std::ostream& os, Prime& prog);

class PrimeException : public std::out_of_range
{
public:
    PrimeException(const char *error) : std::out_of_range(error) {};
};

#endif // PRIME_H
