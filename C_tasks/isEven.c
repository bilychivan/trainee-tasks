/*
Задача isEven

Условие задачи
Считать с клавиатуры целое число.
Если число чётное, вывести на экран yes, в противном случае вывести no.

Пример ввода
17
Пример вывода
no

*/

#include "stdio.h"

int main()
{
	int input_value;
	
	scanf("%d", &input_value);

	if (input_value % 2)
	{
		printf("no\n");
	}
	else
	{
		printf("yes\n");
	}

	return 0;
}