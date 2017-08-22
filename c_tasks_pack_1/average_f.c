/*
Задача average()

Условие задачи
unsigned int average(unsigned int a, unsigned int b)
Вернуть среднее арифметическое двух положительных целых чисел. Использовать
только тип unsigned int.
Если среднее значение не является целым, то округлить его к ближайшему целому в
меньшую сторону.

*/

#include <stdio.h>

unsigned int average(unsigned int a, unsigned int b)
{
    return ((a / 2 + b / 2) + (a % 2 * b % 2));
}

int main()
{
    printf("Average: %u\n", average(1, 2));
    printf("Average: %u\n", average(2, 2));
    printf("Average: %u\n", average(2, 1));

    return 0;
}
