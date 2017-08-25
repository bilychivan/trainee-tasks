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

int power(int n, int k) {
	if (k <= 0) {
		return 1;
	}

	return (n * power(n, --k));
}

int main(void) {
	int res = 0;
	int pos;

	scanf("%d", &res);
	for (pos = 0; pos < res; pos++) {
		printf("%d ", power(2, pos));
	}
	printf("%d\n", power(2, pos));

	return 0;
}