/*
Задача pyramid2

Условие задачи
Вывести числовую пирамидку на total строк.
В первой строке стоит число 1. В последующих строках стоят увеличивающиеся числа
через пробел.

Пример ввода
3
Пример вывода
1
2 3
4 5 6

*/

#include <stdio.h>

int main(void) {
	int total = 0;
	int num = 1;

	scanf("%d", &total);

	for (int row = 0; row < total; row++) {
		for (int col = 0; col < row; col++) {
			printf("%d ", num);
			num += 1;
		}
		printf("%d\n", num);
		num += 1;
	}

	return 0;
}