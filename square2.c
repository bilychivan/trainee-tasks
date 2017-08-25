/*
Задача square2

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
1 2
3 4

*/

#include <stdio.h>

int main(void) {
	int total = 0;
	int num = 1;

	scanf("%d", &total);

	for (int row = 1; row <= total; row++) {
		for (int col = 1; col < total; col++) {
			printf("%d ", num);
			num += 1;
		}
		printf("%d\n", num);
		num += 1;
	}

	return 0;
}