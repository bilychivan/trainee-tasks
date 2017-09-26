/*
Задача multiple3
Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все числа, кратные 3, от нуля до указанного числа включительно.

Пример ввода
17
Пример вывода
0 3 6 9 12 15

*/

#include <stdio.h>

#define MULTIPLE 3

int main(void) {
	int max;
	int step;
	int newMax;

	scanf("%d", &max);

	step = 0;
	for ( ; step % MULTIPLE != 0; ) {
		step += 1;
	}
	newMax = max - MULTIPLE; 
	for ( ; step <= newMax; step += MULTIPLE) {
		printf("%d ", step);
	}
	printf("%d\n", step);

	return 0;
}