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

int main(void) {
	int min = 0;
	int max = 0;

	scanf("%d %d", &min, &max);
	while (min <= max) {
		if (min % 2 == 0) {
			printf("%d\n", min);
		}
		min++;
	}

	return 0;
}