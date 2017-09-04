#ifndef VECTOR_CLASS_H
#define VECTOR_CLASS_H

#include <iostream>

class Vector
{
public:
    Vector();

    Vector(double x, double y);

    double getX() const;
    double getY() const;
    double length() const;

    void operator+=(const Vector& that);
    void operator-=(const Vector& that);

    bool operator==(const Vector& that) const;
    bool operator!=(const Vector& that) const;

    Vector operator+(const Vector& that) const;
    Vector operator-(const Vector& that) const;

private:
    double mX;
    double mY;
};

std::ostream& operator<<(std::ostream& os, const Vector& vector);

#endif // VECTOR_CLASS_H