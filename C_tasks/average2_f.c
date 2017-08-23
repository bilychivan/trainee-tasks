/*
Задача average2()

Условие задачи
int average(int a, int b)
Вернуть среднее арифметическое двух целых чисел. Использовать только тип int.
Если среднее значение не является целым, то округлить его к ближайшему целому в
сторону нуля.

*/

#include "stdio.h"

int average(int a, int b)
{
	int remainder = a % 2 + b % 2;

	return a / 2 + b / 2 + remainder / 2;
}

int main()
{
	int value_1, value_2;
	scanf("%d %d", &value_1, &value_2);

	printf("%d\n", average(value_1, value_2));

	return 0;
}