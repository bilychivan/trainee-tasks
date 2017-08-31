#include "complex.h"

Complex::Complex(double real, double imaginary) : re(real), im(imaginary)
{
}

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

void Complex::operator+=(const Complex& value)
{
    this->re += value.re;
    this->im += value.im;
}

void Complex::operator-=(const Complex& value)
{
    this->re -= value.re;
    this->im -= value.im;
}

void Complex::operator*=(const Complex& value)
{
    double re = this->re;

    this->re = (re * value.re) - (this->im * value.im);
    this->im = (re * value.im) + (this->im * value.re);
}

bool Complex::operator==(const Complex& value) const
{
    return ((this->re == value.re) && (this->im == value.im));
}

bool Complex::operator!=(const Complex& value) const
{
    return !(operator==(value));
}

Complex Complex::operator+(const Complex& value) const
{
    Complex result = *this;

    result += value;

    return result;
}

Complex Complex::operator-(const Complex& value) const
{
    Complex result = *this;

    result -= value;

    return result;
}

Complex Complex::operator*(const Complex& value) const
{
    Complex result = *this;

    result *= value;

    return result;
}

std::ostream& operator<<(std::ostream& stream, Complex& object)
{
    std::cout << std::noshowpos << object.getRe() << std::showpos << object.getIm() << 'i';

    return stream;
}

int main()
{
    Complex complex1(5, 4);
    Complex complex2(3, -2);

    std::cout << ((complex1 == complex2) ? "equal" : "not equal") << std::endl;
    std::cout << ((complex1 != complex2) ? "not equal" : "equal") << std::endl;

    Complex c = complex1 * complex2;

    std::cout << c << std::endl;

    complex1 *= complex2;
    std::cout << complex1 << " | " << complex2 << std::endl;

    return 0;
}