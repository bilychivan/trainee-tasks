/*
Задача max4

Условие задачи
Считать с клавиатуры четыре целых числа и вывести большее из них.
В случае равенства выводить любое.
Данная задача решается без массивов, циклов и функций.

Пример ввода
1 2 3 4
Пример вывода
4

*/

#include "stdio.h"

int main()
{
	int max, value_1, value_2, value_3;
	scanf("%d %d %d %d", &max, &value_1, &value_2, &value_3);

	if (max < value_1)
	{
		max = value_1;
	}

	if (max < value_2)
	{
		max = value_2;
	}
	
	if (max < value_3)
	{
		max = value_3;
	}

	printf("%d\n", max);

	return 0;
}