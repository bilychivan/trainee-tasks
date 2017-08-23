/*
Задача div3

Условие задачи
Считать min, max. Вывести в столбик кратные тройке числа от min до max включительно.

Пример ввода
0 9
Пример вывода
0
3
6
9

*/

#include "stdio.h"

#define divisor 3

int main()
{
	int min, max;

	scanf("%d %d", &min, &max);

	min = (min + divisor - 1) - (min + divisor - 1) % divisor;

	for (; min <= max; min += divisor)
	{
		printf("%d\n", min);
	}

	return 0;
}