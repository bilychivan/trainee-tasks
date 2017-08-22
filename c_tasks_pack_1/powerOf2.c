/*
Задача powerOf2

Условие задачи
Считать с клавиатуры целое неотрицательное число. Вывести через пробел степени
числа 2 от нулевой до заданной. Использовать цикл.

Пример ввода
3
Пример вывода
1 2 4 8

*/

#include <stdio.h>

int main()
{
    unsigned int number;
    scanf("%u", &number);

    unsigned int m = 1;
    for (unsigned int i = 0; i <= number; i++)
    {
        printf("%i ", m);
        m = m * 2;
    }

    return 0;
}
