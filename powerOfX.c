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

int power(int n, int k) {
	if (k <= 0) {
		return 1;
	}

	return (n * power(n, --k));
}

int main(void) {
	int res = 0;
	int num = 0;
	int powerNum;

	scanf("%d %d", &num, &res);
	for (powerNum = 0; powerNum < res; powerNum++) {
		printf("%d ", power(num, powerNum));
	}
	printf("%d\n", power(num, powerNum));

	return 0;
}