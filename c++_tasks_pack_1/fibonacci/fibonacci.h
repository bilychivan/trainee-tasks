#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>
#include <stdexcept>

class Fibonacci
{
private:
    int min;
    int max;
    int index;
    int x;
    int y;
    int num;

private:
    int fib_n(int n);
public:
    Fibonacci(const int nMin, const int size);
    int getIndex() const;
    void next();
    void prev();
    int value();
    bool over() const;
    bool first() const;
    int operator++();
    int operator++(int num);
    int operator--();
    int operator--(int num);
    int operator*();
};

std::ostream& operator<<(std::ostream& os, Fibonacci& prog);

class FibonacciException : public std::out_of_range
{
public:
    FibonacciException(const char *error) : std::out_of_range(error) {};
};

#endif