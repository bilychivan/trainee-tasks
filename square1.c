/*
Задача square1

Условие задачи
Вывести числовой квадрат заданного размера.
В каждой строке числа идут с единицы через пробел.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
1 2
1 2

*/

#include <stdio.h>

int main(void) {
	int total = 0;
	int col;

	scanf("%d", &total);

	for (int row = 1; row <= total; row++) {
		for (col = 1; col < total; col++) {
			printf("%d ", col);
		}
		printf("%d\n", col);
	}

	return 0;
}