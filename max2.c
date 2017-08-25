/*
Задача max2

Условие задачи
Считать с клавиатуры два целых числа и вывести большее из них.
Если числа равны, вывести любое.

Пример ввода
1 2
Пример вывода
2

*/

#include <stdio.h>

int	main(void) {
	int first = 0;
	int second = 0;

	scanf("%d %d", &first, &second);
	if (first > second) {
		printf("%d\n", first);
	} else {
		printf("%d\n", second);
	}

	return 0;
}
