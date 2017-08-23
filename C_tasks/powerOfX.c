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
	unsigned int max;
	int powerOfBase = 1;

	scanf("%d%u", &base, &max);
	
	while (max--)
	{
		printf("%d ", powerOfBase);
		powerOfBase *= base;
	}
	printf("%d\n", powerOfBase);

	return 0;
}