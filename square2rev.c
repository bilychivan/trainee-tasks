/*
Задача square2rev

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Порядок строк обратный.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
3 4
1 2

*/

#include <stdio.h>

int main(void) {
	int total = 0;
	int num;

	scanf("%d", &total);
	for (int row = total; row > 0; row--) {
		num = (row - 1) * total + 1;
		for (int col = 1; col < total; col++) {
			printf("%d ", num);
			num += 1;
		}
		printf("%d\n", num);
		num += 1;
	}

	return 0;
}