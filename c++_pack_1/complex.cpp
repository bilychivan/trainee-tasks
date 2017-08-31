#include "complex.h"

#include <cmath>

Complex::Complex()
    : mRe(0.0), mIm(0.0)
{

}

Complex::Complex(double re, double im)
    : mRe(re), mIm(im)
{

}

double Complex::getRe() const
{
    return mRe;
}

double Complex::getIm() const
{
    return mIm;
}

double Complex::abs() const
{
    return hypot(mRe, mIm);
}

void Complex::operator+=(const Complex& that)
{
    mRe += that.mRe;
    mIm += that.mIm;
}

void Complex::operator-=(const Complex& that)
{
    mRe -= that.mRe;
    mIm -= that.mIm;
}

void Complex::operator*=(const Complex& that)
{
    double re = this->mRe;

    this->mRe = this->mRe * that.mRe - this->mIm * that.mIm;
    this->mIm = re * that.mIm + this->mIm * that.mRe;
}

bool Complex::operator==(const Complex& that) const
{
    return this->mRe == that.mRe && this->mIm == that.mIm;
}

bool Complex::operator!=(const Complex& that) const
{
    return !operator==(that);
}

Complex Complex::operator+(const Complex& that) const
{
    Complex temp = *this;

    temp += that;

    return temp; 
}

Complex Complex::operator-(const Complex& that) const
{
    Complex temp = *this;

    temp -= that;

    return temp; 
}

Complex Complex::operator*(const Complex& that) const
{
    Complex temp = *this;

    temp *= that;

    return temp; 
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << c.getRe();

    if (c.getIm() >= 0.0)
    {
        std::cout << '+';
    }

    std::cout << c.getIm() << "i";

    return os;
}