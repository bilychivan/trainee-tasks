/*
Задача max4

Условие задачи
Считать с клавиатуры четыре целых числа и вывести большее из них.
В случае равенства выводить любое.
Данная задача решается без массивов, циклов и функций.

Пример ввода
1 2 3 4
Пример вывода
4

*/

#include <stdio.h>

int	main(void) {
	int first = 0;
	int second = 0;
	int	third = 0;
	int fourth = 0;

	scanf("%d %d %d %d", &first, &second, &third, &fourth);
	if (first > second && first > third && first > fourth) {
		printf("%d\n", first);
	} else if (second > third && second > fourth) {
		printf("%d\n", second);
	} else if (third > fourth) {
		printf("%d\n", third);
	} else {
		printf("%d\n", fourth);
	}

	return 0;
}
