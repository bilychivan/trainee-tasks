#include "complex.h"

#include <cmath>

Complex::Complex()
    : mRe(0.0)
    , mIm(0.0)
{

}

Complex::Complex(double re, double im)
    : mRe(re)
    , mIm(im)
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
    *this = *this + that;
}

void Complex::operator-=(const Complex& that)
{
    *this = *this - that;
}

void Complex::operator*=(const Complex& that)
{
    *this = *this * that;
}

bool Complex::operator==(const Complex& that) const
{
    return this->mRe == that.mRe && this->mIm == that.mIm;
}

bool Complex::operator!=(const Complex& that) const
{
    return !(*this == that);
}

Complex Complex::operator+(const Complex& that) const
{
    return Complex(this->mRe + that.mRe, this->mIm + that.mIm);
}

Complex Complex::operator-(const Complex& that) const
{
    return Complex(this->mRe - that.mRe, this->mIm - that.mIm);
}

Complex Complex::operator*(const Complex& that) const
{
    return Complex(this->mRe * that.mRe - this->mIm * that.mIm, this->mRe * that.mIm + this->mIm * that.mRe);
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