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

#include <stdio.h>

#define	EVEN 2

int main(void) {
	int max;
	int min;
	int newMax;
	int i;

	scanf("%d %d", &min, &max);

	if (min < 0) {
		i = min - (min % 2);
	} else {
		i = min + (min % 2);
	}
	newMax = max - EVEN;
	for ( ; i <= newMax; i += EVEN) {
		printf("%d ", i);
	}
	printf("%d\n", i);

	return 0;
}