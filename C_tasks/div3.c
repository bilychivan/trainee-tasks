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

int main()
{
	int min, max;
	scanf("%d %d", &min, &max);

	for (int i = min; i <= max; i++)
	{
		if (i % 3 == 0)
			printf("%d\n", i);
	}

	return 0;
}