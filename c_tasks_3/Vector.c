/*
Задача Vector

Условие задачи
С помощью известных вам инструментов реализовать тип Vector (вектор на
координатной плоскости) с координатами x, y типа double. Также реализовать
следующие функции:

void vectorIncrement(Vector *this, Vector other)
void vectorDecrement(Vector *this, Vector other)
int vectorEqual(Vector a, Vector b) - cравнение векторов по координатам
Vector vectorSum(Vector a, Vector b)
Vector vectorDiff(Vector a, Vector b)
double vectorLen(Vector this) – нахождение длины вектора. Воспользоваться
функцией hypot() из библиотеки math.h
void vectorPrint(Vector this) - печать вектора в виде (x, y). Воспользоваться
шаблоном %g

*/

#include <stdio.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Vector;

Vector vectorSum(Vector a, Vector b)
{
    return (Vector){a.x + b.x, a.y + b.y};
}

Vector vectorDiff(Vector a, Vector b)
{
    return (Vector){a.x - b.x, a.y - b.y};
}

void vectorIncrement(Vector *this, Vector other)
{
    *this = vectorSum(*this, other);
}

void vectorDecrement(Vector *this, Vector other)
{
    *this = vectorDiff(*this, other);
}

int vectorEqual(Vector a, Vector b)
{
    return a.x == b.x && a.y == b.y;
}

double vectorLen(Vector this)
{
    return hypot(this.x, this.y);
}

void vectorPrint(Vector this)
{
    printf("(%g, %g)\n", this.x, this.y);
}

void testIncrement(Vector *a, const Vector *b)
{
    vectorPrint(*a);
    vectorPrint(*b);

    vectorIncrement(a, *b);

    vectorPrint(*a);

    printf("--------------------\n");
}

void testDecrement(Vector *a, const Vector *b)
{
    vectorPrint(*a);
    vectorPrint(*b);

    vectorDecrement(a, *b);

    vectorPrint(*a);

    printf("--------------------\n");
}

void testEqual(const Vector *a, const Vector *b)
{
    vectorPrint(*a);
    vectorPrint(*b);

    if (vectorEqual(*a, *b))
    {
        printf("true\n");
    }
    else
    {
        printf("no\n");
    }

    printf("--------------------\n");
}

void testLen(const Vector *a)
{
    vectorPrint(*a);

    printf("%g\n", vectorLen(*a));

    printf("--------------------\n");
}

void testSum(const Vector *a, const Vector *b)
{
    vectorPrint(*a);
    vectorPrint(*b);

    vectorPrint(vectorSum(*a, *b));

    printf("--------------------\n");
}

void testDiff(Vector *a, const Vector *b)
{
    vectorPrint(*a);
    vectorPrint(*b);

    vectorPrint(vectorDiff(*a, *b));

    printf("--------------------\n");
}

void test()
{
    Vector a = {6.0, 2.0}, b = {1.0, 5.0};

    printf("__testIncrement__\n");
    testIncrement(&a, &b);

    printf("__testDecrement__\n");
    testDecrement(&a, &b);

    printf("__testEqual__\n");
    testEqual(&a, &a);

    printf("__testLen__\n");
    testLen(&a);

    printf("__testSum__\n");
    testSum(&a, &b);

    printf("__testDiff__\n");
    testDiff(&a, &b);
}

int main()
{
    test();

    return 0;
}