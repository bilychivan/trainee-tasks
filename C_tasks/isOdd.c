/*
Задача isOdd

Условие задачи
Считать с клавиатуры целое число.
Если число нечётное, вывести на экран yes, в противном случае вывести no.

Пример ввода
17
Пример вывода
yes

*/

#include "stdio.h"

int main()
{
	int a;

	scanf("%d", &a);

	if (a % 2)
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	return 0;
}