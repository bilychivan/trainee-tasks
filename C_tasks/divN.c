/*
Задача divN

Условие задачи
Считать с клавиатуры целые числа min, max и положительный делитель. Вывести в столбик числа, кратные делителю, от min до max включительно.

Пример ввода
0 8 2
Пример вывода
0
2
4
6
8

*/

#include "stdio.h"

int main()
{
	int min, max;
	unsigned int divisor;

	scanf("%d %d %u", &min, &max, &divisor);

	min = (min + divisor - 1) - (min + divisor - 1) % divisor;

	for (; min <= max; min += divisor)
	{
		printf("%d\n", min);
	}

	return 0;
}