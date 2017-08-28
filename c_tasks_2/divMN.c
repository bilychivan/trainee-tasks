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

int gcd(int m, int n)
{
    if (n)
    {
        return gcd(n, m % n);
    }

    return m;
}

int main()
{
    int start, end;
    int m, n;
    int step;

    scanf("%d %d %d %d", &start, &end, &m, &n);

    step = m / gcd(m, n) * n;
    for (start = start / step * step; start <= end; start += step)
    {
        printf("%d\n", start);
    }

    return 0;
}