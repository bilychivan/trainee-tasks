/*
Задача div3

Условие задачи
Считать min, max. Вывести в столбик кратные тройке числа от min до max включительно.

Пример ввода
0 9
Пример вывода
0
3
6
9

*/

#include <stdio.h>

int main(void) {
	int min = 0;
	int max = 0;

	scanf("%d %d", &min, &max);
	while (min <= max) {
		if ((min % 3) == 0) {
			printf("%d\n", min);
		}
		min++;
	}

	return 0;
}