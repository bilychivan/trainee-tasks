/*
Задача pyramid1rev

Условие задачи
Вывести числовую пирамидку на total строк. Порядок строк – обратный.
В каждой строке числа идут от единицы до номера строки через пробел.

Пример ввода
3
Пример вывода
1 2 3
1 2
1

*/

#include <stdio.h>

int main(void) {
	int total = 0;

	scanf("%d", &total);

	for (int row = total; row > 0; row--) {
		for (int col = 1; col < row; col++) {
			printf("%d ", col);
		}
		printf("%d\n", row);
	}

	return 0;
}