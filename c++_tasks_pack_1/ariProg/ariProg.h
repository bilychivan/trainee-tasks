#ifndef ARIPROG_H
#define ARIPROG_H

#include <iostream>
#include <stdexcept>

class AriProg
{
private:
    int num;
    int step;
    int count;
    int index;

public:
    AriProg(const int nStartNum, const int nStep, const int nCount);
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

std::ostream& operator<<(std::ostream& os, AriProg& prog);

class AriProgException : public std::out_of_range
{
public:
    AriProgException(const char *error) : std::out_of_range(error) {};
};

#endif