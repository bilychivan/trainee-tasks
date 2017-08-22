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
    int start, max;
    scanf("%d %d", &start, &max);

    for ( ; start <= max; start++)
    {
        if ((start % 3) == 0)
        {
            printf("%d\n", start);
        }
    }
    return 0;
}
