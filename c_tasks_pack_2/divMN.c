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

int main(void)
{
    int min, max;
    int m, n;
    int step;
    int divMax;

    scanf("%d %d %d %d", &min, &max, &m, &n);

    if (n < m)
    {
        m = n;
    }
    step = m / gcd(m, n) * n;
    if (step < 0)
    {
        step *= -1;
    }
    for (int i = min; i <= max; i += step)
    {
        printf("%d\n", i);
    }

    return 0;
}