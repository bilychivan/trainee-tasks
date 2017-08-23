/*
Задача even

Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все чётные числа от нуля до указанного числа включительно.

Пример ввода
7
Пример вывода
0 2 4 6

*/

#include "stdio.h"

int main()
{
	unsigned int input_value;
	scanf("%u", &input_value);

	for (unsigned int i = 0u; i <= input_value; i++)
	{
		if (i % 2u == 0u)
			printf("%u ", i);
	}
	printf("\b\n");

	return 0;
}