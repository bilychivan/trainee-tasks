/*
Задача pyramid

Условие задачи
Вывести в консоль числовую пирамидку на total строк.
В каждой строке числа идут от единицы до номера строки через пробел.
Пропустить rows строк и cols столбцов.
В выводе не должно быть пустых строк до и после чисел.
Целые положительные числа total, rows и cols считать с клавиатуры.

Пример ввода
5 3 2
Пример вывода
3 4
3 4 5

*/

#include <stdio.h>

int main(void) {
	int total = 0;
	int rows = 0;
	int cols = 0;

	scanf("%d %d %d", &total, &rows, &cols);
	if (rows < cols) {
		rows = cols;
	}
	for (int row = rows + 1; row < total + 1; row++) {
		for (int col = cols + 1; col < row; col++) {
			printf("%d ", col);
		}
		printf("%d\n", row);
	}

	return 0;
}