#include "vector.h"

Vector::Vector() : x(0), y(0) {}

Vector::Vector(double nX, double nY) : x(nX), y(nY) {}

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
    return y != other.y && x != other.x;
}

Vector Vector::operator+(const Vector& other) const
{
    Vector result;

    result.y = y + other.y;
    result.x = x + other.x;

    return result;
}

Vector Vector::operator-(const Vector& other) const
{
    Vector result;

    result.y = y - other.y;
    result.x = x - other.x;

    return result;
}

std::ostream& operator<<(std::ostream& os, const Vector& prog)
{
    return os << '(' << prog.getX() << ', ' << prog.getY() << ')';
}

int main()
{
    Vector a(2.6, 3.7);
    Vector b;

    std::cout << a.getX() << std::endl;
    std::cout << b.getY() << std::endl;
    std::cout << a << std::endl;
    std::cout << a.length() << std::endl;

    return 0;
}