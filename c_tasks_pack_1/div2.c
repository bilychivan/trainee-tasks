/*
Задача div2

Условие задачи
Считать min, max. Вывести в столбик чётные числа от min до max включительно.

Пример ввода
0 8
Пример вывода
0
2
4
6
8

*/

#include <stdio.h>

int main()
{
    const int divisor = 2;
    int start, max;

    scanf("%d %d", &start, &max);

    if ((start % divisor) != 0)
    {
        start = start - start % divisor + divisor;
    }

    for ( ; start <= max; start += divisor)
    {
        printf("%d\n", start);
    }

    return 0;
}
