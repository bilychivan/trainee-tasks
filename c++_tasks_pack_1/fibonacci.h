#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>

class Fibonacci {
    public:
        Fibonacci(const int argFirstIndex, const int argLength);
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
        int index;
        int minIndex;
        int maxIndex;
};

std::ostream& operator<<(std::ostream&, Fibonacci&);

class FibonacciException : public std::out_of_range
{
    public:
        FibonacciException(const char*);
};

#endif // FIBONACCI_H
