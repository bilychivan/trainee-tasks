#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <cmath>

class Vector
{
private:
    double x, y;

public:
    Vector();
    Vector(double inputX, double inputY);
    double getX() const;
    double getY() const;
    double length() const;
    void operator+=(const Vector& other);
    void operator-=(const Vector& other);
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
};

std::ostream& operator<<(std::ostream& os, const Vector& prog);

#endif