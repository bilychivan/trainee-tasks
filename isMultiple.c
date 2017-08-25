/*
Задача isMultiple

Условие задачи
Считать с клавиатуры два целых числа, причем второе из них не равно нулю.
Если первое кратно второму, вывести на экран yes, иначе вывести no.

Пример ввода
25 5
Пример вывода
yes

*/

#include <stdio.h>

int main(void) {
	int first = 0;
	int	sec = 0;

	scanf("%d %d", &first, &sec);
	if ((first % sec) == 0) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	return 0;
}