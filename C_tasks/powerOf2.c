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

int main()
{
	unsigned int input_value;
	scanf("%u", &input_value);

	for (int powerOf2 = 1; powerOf2 <= (1 << input_value); powerOf2 <<= 1)
	{
		printf("%u ", powerOf2);
	}
	printf("\b\n");

	return 0;
}