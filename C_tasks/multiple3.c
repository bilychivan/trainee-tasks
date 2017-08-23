/*
Задача multiple3
Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все числа, кратные 3, от нуля до указанного числа включительно.

Пример ввода
17
Пример вывода
0 3 6 9 12 15

*/

#include "stdio.h"

#define DIVISOR 3

int main()
{
	unsigned int max;

	scanf("%u", &max);

	max = max / DIVISOR * DIVISOR;

	for (unsigned int i = 0; i < max ; i += 3)
	{
		printf("%u ", i);
	}
	printf("%u\n", max);

	return 0;
}