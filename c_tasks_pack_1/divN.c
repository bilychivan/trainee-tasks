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
	int min;
	int max;
	int	divisor;
	int step;

	scanf("%d %d %d", &min, &max, &divisor);

	step = min;
	for ( ; step % divisor != 0; ) {
		step += 1;
	}
	for ( ; step <= max; step += divisor) {
		printf("%d\n", step);
	}
	
	return 0;
}