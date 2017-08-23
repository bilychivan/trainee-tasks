/*
Задача even2

Условие задачи
Считать с клавиатуры два целых числа.
Вывести в строку все чётные числа в промежутке от первого до второго
включительно.
В указанном промежутке гарантировано наличие хотя бы одного числа, подлежащего
выводу.

Пример ввода
7 15
Пример вывода
8 10 12 14

*/

#include "stdio.h"

#define divisor 2

int main()
{
	int min, max;

	scanf("%d %d", &min, &max);

	min = (min + divisor - 1) - (min + divisor - 1) % divisor;
	max = max / divisor * divisor;

	for ( ; min < max; min += divisor)
	{
			printf("%d ", min);
	}
	printf("%d\n", min);

	return 0;
}