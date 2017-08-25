/*
Задача div2

Условие задачи
Считать min, max. Вывести в столбик чётные числа от min до max включительно.

Пример ввода
0 8
Пример вывода
0
2
4
6
8

*/

#include "stdio.h"

#define divisor 2

int main()
{
	int min, max;

	scanf("%d %d", &min, &max);

	min = (min / divisor + 1) * divisor;

	for (; min <= max; min += divisor)
	{
		printf("%d\n", min);
	}

	return 0;
}