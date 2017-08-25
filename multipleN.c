/*
Задача multipleN

Условие задачи
Считать с клавиатуры целое неотрицательное число-максимум.
Считать с клавиатуры целый, не равный нулю делитель.
Вывести в строку числа от нуля до указанного максимума включительно, кратные
заданному делителю.

Пример ввода
99 10
Пример вывода
0 10 20 30 40 50 60 70 80 90

*/

#include <stdio.h>

int main(void) {
	int max;
	int	divisor;
	int step;
	int newMax;

	scanf("%d %d", &max, &divisor);

	if (divisor < 0) {
		divisor *= -1;
	}
	step = 0;
	for ( ; step % divisor != 0; ) {
		step += 1;
	}
	newMax = max - divisor; 
	for ( ; step <= newMax; step += divisor) {
		printf("%d ", step);
	}
	printf("%d\n", step);

	return 0;
}