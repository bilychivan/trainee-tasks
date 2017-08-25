/*
Задача odd

Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все нечётные числа от нуля до указанного числа включительно.

Пример ввода
9
Пример вывода
1 3 5 7 9

*/

#include <stdio.h>

int main(void) {
	int num;
	int odd;

	scanf("%d", &num);

	for (odd = 1; odd < num; odd += 2) {
		printf("%d ", odd);
	}
	printf("%d\n", odd);

	return 0;
}