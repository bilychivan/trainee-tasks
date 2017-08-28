/*
Задача divMN

Условие задачи
Считать с клавиатуры целые числа min, max, m, n, причём m и n положительные.
Вывести на экран в столбик целые числа от min до max включительно, которые без
остатка делятся как на m, так и на n.
В указанном промежутке гарантируется хотя бы одно число, подлежащее выводу.

Пример ввода
0 12 2 3
Пример вывода
0
6
12

*/

#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int abs(int n)
{
    if (n < 0)
    {
        return n * -1;
    }
    return n;
}

int main(void)
{
    int min, max;
    int m, n;
    int step;
    int divMN;

    scanf("%d %d %d %d", &min, &max, &m, &n);

    step = m / gcd(m, n) * n;
    if (step < 0)
    {
        step *= -1;
    }

    divMN = min + abs(min % step);
    for (; divMN <= max; divMN += step)
    {
        printf("%d\n", divMN);
    }

    return 0;
}