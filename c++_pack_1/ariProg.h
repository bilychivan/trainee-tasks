#ifndef ARIPROG_CLASS_H
#define ARIPROG_CLASS_H

#include <iostream>
#include <stdexcept>

class AriProg
{
private:
    int mValue;
    const int mStep;
    const int mSize;
    int mIndex;

public:
    AriProg(int, int, int);

    int getIndex() const;

    void next();
    void prev();

    int value() const;

    bool over() const;
    bool first() const;

    int& operator++();
    int operator++(int);

    int& operator--();
    int operator--(int);

    int& operator*();
};

std::ostream& operator<<(std::ostream&, const AriProg&);

class AriProgException : public std::out_of_range
{
public:
    AriProgException(const char*);
};

#endif // ARIPROG_H