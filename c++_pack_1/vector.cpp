#include "vector.h"

#include <cmath>

Vector::Vector()
    : mX(0.0)
    , mY(0.0)
{

}

Vector::Vector(double x, double y)
    : mX(x)
    , mY(y)
{

}

double Vector::getX() const
{
    return mX;
}

double Vector::getY() const
{
    return mY;
}

double Vector::length() const
{
    return hypot(mX, mY);
}

void Vector::operator+=(const Vector& that)
{
    *this = *this + that;
}

void Vector::operator-=(const Vector& that)
{
    *this = *this - that;
}

bool Vector::operator==(const Vector& that) const
{
    return this->mX == that.mX && this->mY == that.mY;
}

bool Vector::operator!=(const Vector& that) const
{
    return !(*this == that);
}

Vector Vector::operator+(const Vector& that) const
{
    return Vector(this->mX + that.mX, this->mY + that.mY);
}

Vector Vector::operator-(const Vector& that) const
{
    return Vector(this->mX - that.mX, this->mY - that.mY);
}

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
    os << '(' << vector.getX() <<  ", " << vector.getY() << ")";

    return os;
}