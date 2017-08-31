#ifndef ARIPROG_H
#define ARIPROG_H

#include <iostream>

class AriProg {
    public:
        AriProg(const int firstMember, const int step, const int length);
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
        int currentMember;
        int step;
        int length;

        int index;
};

std::ostream& operator<<(std::ostream&, AriProg&);

class AriProgException : public std::out_of_range
{
public:
    AriProgException(const char*);
};


#endif // ARIPROG_H
