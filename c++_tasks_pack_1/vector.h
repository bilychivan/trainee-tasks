#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

class Vector
{
    public:
        Vector();
        Vector(double argX, double argY);
        double getX() const;
        double getY() const;
        double length() const;
        void operator+=(const Vector& other);
        void operator-=(const Vector& other);
        bool operator==(const Vector& other) const;
        bool operator!=(const Vector& other) const;
        Vector operator+(const Vector& other) const;
        Vector operator-(const Vector& other) const;

    private:
        double x;
        double y;
};

std::ostream& operator<<(std::ostream& stream, const Vector& object);

class VectorException : public std::out_of_range
{
public:
    VectorException(const char*);
};

#endif // VECTOR_H
