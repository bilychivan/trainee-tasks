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

#include "stdio.h"

int main()
{
	int firstMember, step, amount;

	scanf("%d", &firstMember);
	scanf("%d", &step);
	scanf("%d", &amount);

	for(int i = 0, value = firstMember; i < amount; i++, value += step)
		printf("%d ", value);
	printf("\n");
}