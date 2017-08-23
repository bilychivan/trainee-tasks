/*
Задача average()

Условие задачи
unsigned int average(unsigned int a, unsigned int b)
Вернуть среднее арифметическое двух положительных целых чисел. Использовать
только тип unsigned int.
Если среднее значение не является целым, то округлить его к ближайшему целому в
меньшую сторону.

*/

#include "stdio.h"

unsigned int average(unsigned int a, unsigned int b)
{
	return a / 2 + b / 2 + (a % 2 + b % 2) / 2;
}

int main()
{
	unsigned int value_1, value_2;
	scanf("%u %u", &value_1, &value_2);

	printf("%u\n", average(value_1, value_2));

	return 0;
}