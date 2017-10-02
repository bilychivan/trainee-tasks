/*
Задача isOdd

Условие задачи
Считать с клавиатуры целое число.
Если число нечётное, вывести на экран yes, в противном случае вывести no.

Пример ввода
17
Пример вывода
yes

*/

#include <stdio.h>

int main(void) {
	int res;

	scanf("%d", &res);
	
	if (res % 2 == 0) {
		printf("no\n");
	} else {
		printf("yes\n");
	}

	return 0;
}