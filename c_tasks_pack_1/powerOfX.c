/*
Задача powerOfX

Условие задачи
Считать с клавиатуры целое основание и целый неотрицательный показатель. Вывести
через пробел степени числа основания от нулевой до заданной.

Пример ввода
2 3
Пример вывода
1 2 4 8

*/

#include <stdio.h>

int main()
{
    unsigned int base;
    unsigned int number;
    scanf("%u %u", &base, &number);

    unsigned int m = 1;
    for (unsigned int i = 0; i <= number; i++)
    {
        printf("%i ", m);
        m = m * base;
    }

    return 0;
}
