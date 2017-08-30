/*
Задача Complex

Условие задачи
С помощью известных вам инструментов реализовать тип Complex для хранения
комплексных чисел.

Теория:
Комплексное число задается формулой a + bi, где a и b - вещественные числа, i =
sqrt(-1) (мнимая единица); a называют действительной частью (принято обозначать
re), b называют мнимой частью (принято обозначать im).

Действия над комплексными числами:
* Сравнение: a + bi = c + di означает, что a = c и b = d (два комплексных числа
равны между собой тогда и только тогда, когда равны их действительные и мнимые
части).
* Сложение: (a + bi) + (c + di) = (a + c) + (b + d)i
* Вычитание: (a + bi) - (c + di) = (a - c) + (b - d)i
* Умножение: (a + bi)*(c + di) = ...

Модуль комплексного числа вычисляется как квадратный корень из суммы квадратов
его действительной и мнимой частей.

void complexIncrement(Complex *this, Complex other)
void complexDecrement(Complex *this, Complex other)
void complexMultiply(Complex *this, Complex other)
Complex complexSum(Complex a, Complex b)
Complex complexDiff(Complex a, Complex b)
Complex complexProduct(Complex a, Complex b)
int complexEqual(Complex a, Complex b)
double complexAbs(Complex this) - нахождение модуля комплексного числа.
Воспользоваться функцией hypot() из библиотеки math.h
void complexPrint(Complex this) - печать комплексного числа в виде a+bi.
Воспользоваться шаблоном %g. Проследить за знаком мнимой части. Обеспечить
возможность вывода вида 3+7i is not equal to 4+2i.

*/

#include <stdio.h>
#include <math.h>

typedef struct
{
    double re;
    double im;
} Complex;

Complex complexSum(Complex a, Complex b)
{
    return (Complex){a.re + b.re, a.im + b.im};
}

Complex complexDiff(Complex a, Complex b)
{
    return (Complex){a.re - b.re, a.im - b.im};
}

Complex complexProduct(Complex a, Complex b)
{
    return (Complex){a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re};
}

void complexIncrement(Complex *this, Complex other)
{
    *this = complexSum(*this, other);
}

void complexDecrement(Complex *this, Complex other)
{
    *this = complexDiff(*this, other);
}

void complexMultiply(Complex *this, Complex other)
{
    *this = complexProduct(*this, other);
}

int complexEqual(Complex a, Complex b)
{
    return a.re == b.re && a.im == b.im;
}

double complexAbs(Complex this)
{
    return hypot(this.re, this.im);
}

void complexPrint(Complex this)
{
    printf("%g", this.re);

    if (this.im >= 0.0)
    {
        printf("+");
    }

    printf("%gi\n", this.im);
}

void testIncrement(Complex *a, const Complex *b)
{
    complexPrint(*a);
    complexPrint(*b);

    complexIncrement(a, *b);

    complexPrint(*a);

    printf("--------------------\n");
}

void testDecrement(Complex *a, const Complex *b)
{
    complexPrint(*a);
    complexPrint(*b);

    complexDecrement(a, *b);

    complexPrint(*a);

    printf("--------------------\n");
}

void testMultiply(Complex a, Complex b)
{
    complexPrint(a);
    complexPrint(b);

    complexMultiply(&a, b);

    complexPrint(a);

    printf("--------------------\n");
}

void testSum(const Complex *a)
{
    complexPrint(*a);
    complexPrint(*a);

    complexPrint(complexSum(*a, *a));

    printf("--------------------\n");
}

void testDiff(const Complex *a)
{
    complexPrint(*a);
    complexPrint(*a);

    complexPrint(complexDiff(*a, *a));

    printf("--------------------\n");
}

void testProduct(const Complex *a, const Complex *b)
{
    complexPrint(*a);
    complexPrint(*b);

    complexPrint(complexProduct(*a, *b));

    printf("--------------------\n");
}

void testEqual(const Complex *a, const Complex *b)
{
    complexPrint(*a);
    complexPrint(*b);

    if (complexEqual(*a, *b))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    printf("--------------------\n");
}

void testAbs(const Complex *a)
{
    complexPrint(*a);

    printf("%g\n", complexAbs(*a));

    printf("--------------------\n");
}

void test()
{
    Complex a = {3.0, 2.0}, b = {1.0, 4.0};

    printf("__testIncrement__\n");
    testIncrement(&a, &b);

    printf("__testDecrement__\n");
    testDecrement(&a, &b);

    printf("__testMultiply__\n");
    testMultiply(a, b);

    printf("__testSum__\n");
    testSum(&a);

    printf("__testDiff__\n");
    testDiff(&a);

    printf("__testProduct__\n");
    testProduct(&a, &b);

    printf("__testEqual__\n");
    testEqual(&a, &a);

    printf("__testAbs__\n");
    testAbs(&a);
}

int main()
{
    test();

    return 0;
}