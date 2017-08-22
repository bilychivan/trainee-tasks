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
    int start, max;
    scanf("%d %d", &start, &max);

    for ( ; start <= max; start++)
    {
        if ((start % 2) == 0)
        {
            printf("%d\n", start);
        }
    }
    return 0;
}
