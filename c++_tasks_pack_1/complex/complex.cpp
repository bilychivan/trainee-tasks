#include "complex.h"

Complex::Complex() : re(0), im(0) {}

Complex::Complex(double nRe, double nIm) : re(nRe), im(nIm) {}

double Complex::getRe() const
{
    return re;
}

double Complex::getIm() const
{
    return im;
}

double Complex::abs() const
{
    return hypot(re, im);
}

void Complex::operator+=(const Complex& other)
{
    re += other.re;
    im += other.im;
}

void Complex::operator-=(const Complex& other)
{
    re -= other.re;
    im -= other.im;
}

void Complex::operator*=(const Complex& other)
{
    double newRe = this->re;

    this->re = (newRe * other.re) - (this->im * other.im);
    this->im = (newRe * other.im) + (this->im * other.re);
    this->re = newRe;
}

Complex Complex::operator+(const Complex& other) const
{
    Complex result = *this;

    result += other;

    return result;
}

Complex Complex::operator-(const Complex& other) const
{
    Complex result;

    result.im = im - other.im;
    result.re = re - other.re;

    return result;
}

Complex Complex::operator*(const Complex& other) const
{
    Complex result;

    result *= other;

    return result;
}

bool Complex::operator==(const Complex& other) const
{
    return im == other.im && re == other.re;
}

bool Complex::operator!=(const Complex& other) const
{
    return !operator==(other);
}

std::ostream& operator<<(std::ostream& os, const Complex& comp)
{
    if (comp.getIm() < 0)
    {
        return os << comp.getRe() << comp.getIm();
    }
    else
    {
        return os << comp.getRe() << '+' << comp.getIm();
    }
}