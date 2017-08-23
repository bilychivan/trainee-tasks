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

#define divisor 2

int main()
{
	unsigned int max;

	scanf("%u", &max);

	max = max / divisor * divisor;

	for (unsigned int i = 0u; i < max; i += divisor)
	{
			printf("%u ", i);
	}
	printf("%u\n", max);

	return 0;
}