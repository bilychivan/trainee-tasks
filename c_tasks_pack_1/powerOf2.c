/*
Задача powerOf2

Условие задачи
Считать с клавиатуры целое неотрицательное число. Вывести через пробел степени
числа 2 от нулевой до заданной. Использовать цикл.

Пример ввода
3
Пример вывода
1 2 4 8

*/

#include <stdio.h>

int main(void) {
	int len;
	int base = 2;
	int power = 1;

	scanf("%d", &len);

	for (int i = 0; i < len; i++) {
		printf("%d ", power);
		power *= base;
	}
	printf("%d\n", power);

	return 0;
}