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
    const int power = 2;
    unsigned int number;
    unsigned int m = 1;

    scanf("%u", &number);

    for (unsigned int i = 0; i < number; i++)
    {
        printf("%i ", m);
        m = m * power;
    }
    printf("%i\n", m);

    return 0;
}
