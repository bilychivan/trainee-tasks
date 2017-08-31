#include "vector.h"

Vector::Vector(double argX, double argY)
{
    x = argX;
    y = argY;
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
    return !(*this == other);
}

Vector Vector::operator+(const Vector& other) const
{
    Vector v = *this;

    v += other;

    return v;
}

Vector Vector::operator-(const Vector& other) const
{
    Vector v = *this;

    v -= other;

    return v;
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