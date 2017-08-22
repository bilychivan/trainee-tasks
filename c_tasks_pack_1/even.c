/*
Задача even

Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все чётные числа от нуля до указанного числа включительно.

Пример ввода
7
Пример вывода
0 2 4 6

*/

#include <stdio.h>

int main()
{
    const int step = 2;
    unsigned int max;

    scanf("%u", &max);

    if ((max % step) != 0)
    {
        max--;
    }

    for (unsigned int i = 0; i < max; i += step)
    {
        printf("%u ", i);
    }

    if ((max % step) == 0)
    {
        printf("%u\n", max);
    }
    else
    {
        printf("\n");
    }

    return 0;
}
