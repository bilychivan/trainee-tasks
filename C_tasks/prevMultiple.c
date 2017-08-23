/*
Задача prevMultiple

Условие задачи
Считать с клавиатуры два целых числа - делимое и делитель, причем делитель не равен нулю.
Вывести на экран наибольшее число, кратное делителю, не превышающее делимое.

Пример ввода
15 6
Пример вывода
12

*/

#include "stdio.h"

int main()
{
	int divisible, divisor;
	int prev_multiple;

	scanf("%d%d", &divisible, &divisor);

	if (divisor < 0)
	{
		divisor = -divisor;
	}

	prev_multiple = divisible / divisor * divisor;

	if (divisible < 0 && divisible % 2)
	{
		prev_multiple -= divisor;
	}

	printf("%d\n", prev_multiple);

	return 0;
}