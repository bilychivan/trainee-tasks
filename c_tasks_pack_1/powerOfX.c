/*
Задача powerOfX

Условие задачи
Считать с клавиатуры целое основание и целый неотрицательный показатель. Вывести
через пробел степени числа основания от нулевой до заданной.

Пример ввода
2 3
Пример вывода
1 2 4 8

*/

#include <stdio.h>

int main(void) {
	int len;
	int base;
	int power = 1;

	scanf("%d %d", &base, &len);

	for (int i = 0; i < len; i++) {
		printf("%d ", power);
		power *= base;
	}
	printf("%d\n", power);

	return 0;
}