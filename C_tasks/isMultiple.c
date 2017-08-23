/*
Задача isMultiple

Условие задачи
Считать с клавиатуры два целых числа, причем второе из них не равно нулю.
Если первое кратно второму, вывести на экран yes, иначе вывести no.

Пример ввода
25 5
Пример вывода
yes

*/

#include "stdio.h"

int main()
{
	int value_1, value_2;
	scanf("%d %d", &value_1, &value_2);

	if (value_1 % value_2)
	{
		printf("no\n");
	}
	else
	{
		printf("yes\n");
	}

	return 0;
}