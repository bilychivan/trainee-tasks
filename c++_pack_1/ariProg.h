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
    AriProg(int start, int step, int size);

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
};

std::ostream& operator<<(std::ostream& os, const AriProg& sequence);

class AriProgException : public std::runtime_error
{
public:
    AriProgException(const std::string& message);
};

#endif // ARIPROG_H