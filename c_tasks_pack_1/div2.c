/*
Задача div2

Условие задачи
Считать min, max. Вывести в столбик чётные числа от min до max включительно.

Пример ввода
0 8
Пример вывода
0
2
4
6
8

*/

#include <stdio.h>

#define STEP 2

int main(void) {
	int min;
	int max;
	int multiple;

	scanf("%d %d", &min, &max);

	multiple = min;
	for ( ; multiple % STEP != 0; ) {
		multiple += 1;
	}
	for ( ; multiple <= max; multiple += STEP) {
		printf("%d\n", multiple);
	}
	
	return 0;
}