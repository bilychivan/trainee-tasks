/*
Задача max4

Условие задачи
Считать с клавиатуры четыре целых числа и вывести большее из них.
В случае равенства выводить любое.
Данная задача решается без массивов, циклов и функций.

Пример ввода
1 2 3 4
Пример вывода
4

*/

#include <stdio.h>

int main(void) {
	int a;
	int b;
	int c;
	int d;
	int max;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	max = a;
	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}
	if (d > max) {
		max = d;
	}
	printf("%d\n", max);

	return 0;
}