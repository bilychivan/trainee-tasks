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

int main(void)
{
	int	first = 0;
	int	step = 0;
	int	count = 0;

	scanf("%d %d %d", &first, &step, &count);
	for (int i = count; (i - 1) > 0; i--)
	{
		printf("%d ", first);
		first += step;
	}
	printf("%d\n", first);

	return 0;
}