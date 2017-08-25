/*
Задача isEven

Условие задачи
Считать с клавиатуры целое число.
Если число чётное, вывести на экран yes, в противном случае вывести no.

Пример ввода
17
Пример вывода
no

*/

#include <stdio.h>

int main(void) {
	int res = 0;

	scanf("%d", &res);
	if (res % 2 == 0) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	return 0;
}