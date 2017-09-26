/*
Задача prevMultiple

Условие задачи
Считать с клавиатуры два целых числа - делимое и делитель, причем делитель не равен нулю.
Вывести на экран наибольшее число, кратное делителю, не превышающее делимое.

Пример ввода
15 6
Пример вывода
12

*/

#include <stdio.h>

int main(void) {
	int dividend;
	int divider;
	int result;

	scanf("%d %d", &dividend, &divider);

	if (divider < 0) {
		divider *= -1;
	}
	result = dividend - (dividend % divider);
	printf("%d\n", result);

	return 0;
}