#ifndef PRIME_H
#define PRIME_H

#include <iostream>
#include <vector>

class Prime
{
    public:
        Prime(const int argFirstIndex, const int argLength);
        int getIndex() const;
        void next();
        void prev();
        int value();
        bool last() const;
        bool first() const;
        int operator++();
        int operator++(int);
        int operator--();
        int operator--(int);
        int operator*();

    private:
        struct PrimeCachedElement
        {
            bool available;
            unsigned int value;
        };

        struct PrimeCacheHead
        {
            unsigned int startValue;
            unsigned int startIndex;
        };

        int index;
        int minIndex;
        int maxIndex;

        static std::vector<PrimeCachedElement> cache;
        static PrimeCacheHead cacheHead;

        friend unsigned int getNthPrime(Prime const *prime, unsigned int n);
        friend unsigned int calculateNthPrime(Prime const *prime, unsigned int n);
};

std::ostream& operator<<(std::ostream&, Prime&);

class PrimeException : public std::out_of_range
{
public:
    PrimeException(const char*);
};

#endif // PRIME_H
