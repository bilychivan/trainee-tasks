/*
Задача even

Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все чётные числа от нуля до указанного числа включительно.

Пример ввода
7
Пример вывода
0 2 4 6

*/

#include <stdio.h>

#define	EVEN 2

int main(void) {
	int max;
	int newMax;
	int i;

	scanf("%d", &max);

	newMax = max - EVEN;
	for (i = 0; i <= newMax; i += EVEN) {
		printf("%d ", i);
	}
	printf("%d\n", i);

	return 0;
}