/*
Задача ariProg

Условие задачи
Считать с клавиатуры три целых числа - первый член, шаг и количество членов
арифметической прогрессии. Вывести в строку через пробел члены заданной
прогрессии.
Задаваемое количество больше нуля.

Пример ввода
12 2 4
Пример вывода
12 14 16 18

*/

#include <stdio.h>

int main()
{
	int counter;
	int step;
	int number;

	scanf("%d %d %d", &counter, &step, &number);

	for (; number > 1; number--)
	{
		printf("%i ", counter);
		counter += step;
	}
	printf("%i\n", counter);

	return 0;
}
