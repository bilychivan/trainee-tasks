/*
Задача multipleN

Условие задачи
Считать с клавиатуры целое неотрицательное число-максимум.
Считать с клавиатуры целый, не равный нулю делитель.
Вывести в строку числа от нуля до указанного максимума включительно, кратные
заданному делителю.

Пример ввода
99 10
Пример вывода
0 10 20 30 40 50 60 70 80 90

*/

#include "stdio.h"

int main()
{
	unsigned int max;
	int divider;

	scanf("%u %d", &max, &divider);

	if(divider < 0)
	{
		divider = -divider;
	}

	max = max / divider * divider;

	for (unsigned int i = 0u; i < max; i += divider)
	{
		printf("%u ", i);
	}
	printf("%u\n", max);

	return 0;
}