#ifndef FIBONACCI_CLASS_H
#define FIBONACCI_CLASS_H

#include <iostream>
#include <stdexcept>
#include <string>

class Fibonacci
{
public:
    Fibonacci(int index, int size);

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

    int operator*();

private:
    int fib(int n) const;

    int mCurrent;
    int mIndex;
    const int mInitialIndex;
    const int mLastIndex;
};

std::ostream& operator<<(std::ostream& os, const Fibonacci& f);

class FibonacciException : public std::runtime_error
{
public:
    explicit FibonacciException(const std::string& message);
};

#endif // FIBONACCI_CLASS_H