/*
Задача multiple5
Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все числа, кратные 5, от нуля до указанного числа включительно.

Пример ввода
17
Пример вывода
0 5 10 15

*/

#include "stdio.h"

#define DIVISOR 5

int main()
{
	unsigned int max;

	scanf("%u", &max);

	max = max / DIVISOR * DIVISOR;

	for (unsigned int i = 0; i < max; i += DIVISOR)
	{
		printf("%u ", i);
	}
	printf("%u\n", max);

	return 0;
}