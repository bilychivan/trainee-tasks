#include "vector.h"

Vector::Vector(double x, double y) : x(x), y(y)
{
}

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
    return ((x == other.x) && (y == other.y));
}

bool Vector::operator!=(const Vector& other) const
{
    return !(operator==(other));
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

std::ostream& operator<<(std::ostream& stream, const Vector& object)
{
    std::cout << "(" << object.getX() << ", " << object.getY() << ")";

    return stream;
}

VectorException::VectorException(const char* str) : std::out_of_range(str) {}

int main()
{
    Vector v1(2, 2);
    Vector v2(4, 4);

    std::cout << (v1 - v2).length() << std::endl;

    return 0;
}