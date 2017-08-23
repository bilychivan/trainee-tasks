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
	int divisible, divisor;

	scanf("%d%d", &divisible, &divisor);

	printf("%d\n", (divisible / divisor + 1) * divisor);

	return 0;
}