/*
Задача divN

Условие задачи
Считать с клавиатуры целые числа min, max и положительный делитель. Вывести в столбик числа, кратные делителю, от min до max включительно.

Пример ввода
0 8 2
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
	int	divider = 0;

	scanf("%d %d %d", &min, &max, &divider);
	while (min <= max) {
		if (min % divider == 0) {
			printf("%d\n", min);
		}
		min++;
	}

	return 0;
}