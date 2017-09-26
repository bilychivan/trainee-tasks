/*
Задача average()

Условие задачи
unsigned int average(unsigned int a, unsigned int b)
Вернуть среднее арифметическое двух положительных целых чисел. Использовать
только тип unsigned int.
Если среднее значение не является целым, то округлить его к ближайшему целому в
меньшую сторону.

*/

#include <stdio.h>

unsigned int average(unsigned int a, unsigned int b) {
	unsigned int rem = (a % 2) + (b % 2);

	if (rem > 1) {
		return ((a / 2) + (b / 2) + (rem / 2));
	}

	return (a / 2) + (b / 2);
}