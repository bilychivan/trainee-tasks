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

int main()
{
    int head, max;
    int m, n;
    int step;

    scanf("%d %d %d %d", &head, &max, &m, &n);

    if (n > m)
    {
        int tmp = n;
        n = m;
        m = tmp;
    }

    if ((m % n) == 0)
    {
        if (m > n)
        {
            step = m;
        }
        else
        {
            step = n;
        }
    }
    else
    {
        step = m * n;
    }

    head = (head / step) * step;
    if (head >= 0)
    {
        head += step;
    }

    for (; head <= max; head += step)
    {
        printf("%d\n", head);
    }

    return 0;
}