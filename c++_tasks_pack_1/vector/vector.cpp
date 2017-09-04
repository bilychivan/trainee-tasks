#include "vector.h"

Vector::Vector() : x(0), y(0) {}

Vector::Vector(double inputX, double inputY) : x(inputX), y(inputY) {}

double Vector::getX() const
{
    return x;
}

double Vector::getY() const
{
    return y;
}

double Vector::length() const
{
    return hypot(x, y);
}

void Vector::operator+=(const Vector& other)
{
    x += other.x;
    y += other.y;
}

void Vector::operator-=(const Vector& other)
{
    x -= other.x;
    y -= other.y;
}

bool Vector::operator==(const Vector& other) const
{
    return y == other.y && x == other.x;
}

bool Vector::operator!=(const Vector& other) const
{
    return !operator==(other);
}

Vector Vector::operator+(const Vector& other) const
{
    Vector result = *this;

    result += other;

    return result;
}

Vector Vector::operator-(const Vector& other) const
{
    Vector result = *this;

    result -= other;

    return result;
}

std::ostream& operator<<(std::ostream& os, const Vector& prog)
{
    return os << '(' << prog.getX() << ", " << prog.getY() << ')';
}