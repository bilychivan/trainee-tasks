/*
Задача nextMultiple

Условие задачи
Считать с клавиатуры два целых числа - делимое и делитель, причем делитель не равен нулю.
Вывести на экран наименьшее число, кратное делителю, не меньшее делимого.
Пример ввода
15 6
Пример вывода
18

*/

#include "stdio.h"

int main()
{
	int divisible, divisor, nextmultiple;

	scanf("%d %d", &divisible, &divisor);

	if (divisor < 0)
	{
		divisor = -divisor;
	}

	nextmultiple = (divisible + divisor - 1) - (divisible + divisor - 1) % divisor;

	if (divisor < 0)
	{
		nextmultiple -= divisor;
	}

	printf("%d\n", nextmultiple);

	return 0;
}