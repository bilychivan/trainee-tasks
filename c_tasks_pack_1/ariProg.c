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
	int counter = 0;
	int step = 0;
	int number = 0;

	scanf("%d %d %d", &counter, &step, &number);

	while (number > 1)
	{
		printf("%i ", counter);
		counter += step;
		number--;
	}
	printf("%i\n", counter);
	return 0;
}
