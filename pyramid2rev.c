/*
Задача pyramid2rev

Условие задачи
Вывести числовую пирамидку на total строк. Порядок строк – обратный.
В первой строке стоит число 1. В последующих строках стоят увеличивающиеся числа
через пробел.

Пример ввода
3
Пример вывода
4 5 6
2 3
1

*/

#include <stdio.h>

int main(void) {
	int total = 0;
	int num = 1;

	scanf("%d", &total);

	for (int row = total; row > 0; row--) {
		num = (row * (row + 1)) / 2 - row + 1;
		for (int col = 1; col < row; col++) {
			printf("%d ", num);
			num += 1;
		}
		printf("%d\n", num);
		num += 1;
	}

	return 0;
}