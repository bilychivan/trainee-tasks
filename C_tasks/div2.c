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

int main()
{
	int min, max;
	scanf("%d %d", &min, &max);

	for (int i = min; i <= max; i++)
	{
		if (i % 2 == 0)
			printf("%d\n", i);
	}

	return 0;
}