/*
Задача odd2

Условие задачи
Считать с клавиатуры два целых числа, причём второе число не меньше первого.
Вывести в строку все нечётные числа в промежутке от первого до второго включительно.
В указанном промежутке гарантируется на вывод хотя бы одно число.

Пример ввода
7 15
Пример вывода
7 9 11 13 15

*/

#include <stdio.h>

int main()
{
    const int divisor = 2;
    int start, max;

    scanf("%u %u", &start, &max);

    if ((start % divisor) == 0)
    {
        start++;
    }

    if ((max % divisor) == 0)
    {
        max--;
    }

    for (int i = start; i < max; i += divisor)
    {
        printf("%d ", i);
    }

    if ((max % divisor) != 0)
    {
        printf("%d\n", max);
    }
    else
    {
        printf("\n");
    }

    return 0;
}
