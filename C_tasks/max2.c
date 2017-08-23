/*
Задача max2

Условие задачи
Считать с клавиатуры два целых числа и вывести большее из них.
Если числа равны, вывести любое.

Пример ввода
1 2
Пример вывода
2

*/

#include "stdio.h"

int main()
{
	int value_1, value_2;
	scanf("%d %d", &value_1, &value_2);

	if (value_1 > value_2)
	{
		printf("%d\n", value_1);
	}
	else
	{
		printf("%d\n", value_2);
	}

	return 0;
}