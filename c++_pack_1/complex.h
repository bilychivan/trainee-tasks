#ifndef COMPLEX_CLASS_H
#define COMPLEX_CLASS_H

#include <iostream>

class Complex
{
private:
    double mRe;
    double mIm;

public:
    Complex();
    Complex(double re, double im);

    double getRe() const;
    double getIm() const;

    double abs() const;

    void operator+=(const Complex& that);
    void operator-=(const Complex& that);
    void operator*=(const Complex& that);

    bool operator==(const Complex& that) const;
    bool operator!=(const Complex& that) const;

    Complex operator+(const Complex& that) const;
    Complex operator-(const Complex& that) const;
    Complex operator*(const Complex& that) const;
};

std::ostream& operator<<(std::ostream& os, const Complex& c);

#endif // COMPLEX_CLASS_H