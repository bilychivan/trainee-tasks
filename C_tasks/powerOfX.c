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

#include "stdio.h"

int main()
{
	int base;
	unsigned int input_power;
	scanf("%d%u", &base, &input_power);

	int powerOfBase = 1;
	for (unsigned int i = 0; i <= input_power; i++, powerOfBase *= base)
	{
		printf("%d ", powerOfBase);
	}
	printf("\b\n");

	return 0;
}