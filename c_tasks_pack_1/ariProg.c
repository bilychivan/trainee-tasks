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
	int first_member = 0;
	int step = 0;
	int count = 0;
	scanf("%i %i %i", &first_member, &step, &count);
	
	for (int i = 0; i < count; i++)
	{
		printf("%i ", first_member);
		first_member += step;
	}
	return 0;
}