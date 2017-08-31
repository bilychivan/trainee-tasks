#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <math.h>

class Complex {
    public:
        Complex();
        Complex(double real, double imaginary);
        double getRe() const;
        double getIm() const;
        double abs() const;
        void operator+=(const Complex& value);
        void operator-=(const Complex& value);
        void operator*=(const Complex& value);
        bool operator==(const Complex& value) const;
        bool operator!=(const Complex& value) const;
        Complex operator+(const Complex& value) const;
        Complex operator-(const Complex& value) const;
        Complex operator*(const Complex& value) const;

    private:
        double re;
        double im;
};

std::ostream& operator<<(std::ostream&, const Complex&);

#endif // COMPLEX_H
