/*
Задача even2

Условие задачи
Считать с клавиатуры два целых числа.
Вывести в строку все чётные числа в промежутке от первого до второго
включительно.
В указанном промежутке гарантировано наличие хотя бы одного числа, подлежащего
выводу.

Пример ввода
7 15
Пример вывода
8 10 12 14

*/

#include <stdio.h>

int main()
{
    const int step = 2;
    int start, max;

    scanf("%d %d", &start, &max);

    if ((start % step) != 0)
    {
        start++;
    }

    if ((max % step) != 0)
    {
        max--;
    }

    for (int i = start; i < max; i += step)
    {
        printf("%d_", i);
    }

    if ((max % step) == 0)
    {
        printf("%d\n", max);
    }
    else
    {
        printf("\n");
    }

    return 0;
}
