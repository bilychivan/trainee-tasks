#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex
{
private:
    double re, im;

public:
    Complex();
    Complex(double re, double im);
    double getRe() const;
    double getIm() const;
    double abs() const;
    void operator+=(const Complex& other);
    void operator-=(const Complex& other);
    void operator*=(const Complex& other);
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
};

std::ostream& operator<<(std::ostream& os, const Complex& comp);

#endif