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

#include "stdio.h"

#define BASE 2

int main()
{
	unsigned int max;
	unsigned int powerOf2 = 1;

	scanf("%u", &max);

	while (max--)
	{
		printf("%u ", powerOf2);
		powerOf2 *= BASE;
	}
	printf("%u\n", powerOf2);

	return 0;
}