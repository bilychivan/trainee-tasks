/*
Задача odd2

Условие задачи
Считать с клавиатуры два целых числа, причём второе число не меньше первого.
Вывести в строку все нечётные числа в промежутке от первого до второго включительно.
В указанном промежутке гарантируется на вывод хотя бы одно число.

Пример ввода
7 15
Пример вывода
7 9 11 13 15

*/

#include "stdio.h"

#define DIVISOR 2

int main()
{
	int start, finish;

	scanf("%d %d", &start, &finish);

	start = start / DIVISOR * DIVISOR + 1;
	finish = (finish + DIVISOR - 1) - (finish + DIVISOR - 1) % DIVISOR - DIVISOR;

	if (start < 0)
	{
		start -= DIVISOR;
	}

	for ( ; start < finish; start += DIVISOR)
	{
		printf("%d ", start);
	}
	printf("%d\n", start);

	return 0;
}