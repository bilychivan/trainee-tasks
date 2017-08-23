/*
Задача countdown

Условие задачи
Считать с клавиатуры целое неотрицательное число.
Вывести в строку убывающий ряд чисел от заданного до нуля.

Пример ввода
7
Пример вывода
7 6 5 4 3 2 1 0

*/

#include "stdio.h"

int main()
{
	unsigned int input_value;
	scanf("%u", &input_value);

	for (int i = 0; i <= input_value; ++i)
	{
		printf("%u ", input_value - i);
	}
	printf("\b\n");

	return 0;
}
