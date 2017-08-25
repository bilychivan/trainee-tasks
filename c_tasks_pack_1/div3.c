/*
Задача div3

Условие задачи
Считать min, max. Вывести в столбик кратные тройке числа от min до max включительно.

Пример ввода
0 9
Пример вывода
0
3
6
9

*/

#include <stdio.h>

int main()
{
    const int divisor = 3;
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
