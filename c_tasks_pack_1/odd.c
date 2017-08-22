/*
Задача odd

Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все нечётные числа от нуля до указанного числа включительно.

Пример ввода
9
Пример вывода
1 3 5 7 9

*/

#include <stdio.h>

#define DIVISOR 2

int main()
{
    unsigned int max;

    scanf("%u", &max);

    if ((max % DIVISOR) == 0)
    {
        max--;
    }

    for (unsigned int i = 1; i < max; i += DIVISOR)
    {
        printf("%u ", i);
    }

    if ((max % DIVISOR) != 0)
    {
        printf("%u\n", max);
    }
    else
    {
        printf("\n");
    }

    return 0;
}
