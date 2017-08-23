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
	int compared_value, a, b, c;
	
	scanf("%d %d %d %d", &compared_value, &a, &b, &c);

	if (compared_value < a)
	{
		compared_value = a;
	}

	if (compared_value < b)
	{
		compared_value = b;
	}

	if (compared_value < c)
	{
		compared_value = c;
	}

	printf("%d\n", compared_value);

	return 0;
}