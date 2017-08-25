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
	int Remainder = (a % 2) + (b % 2);

	return ((a / 2) + (b / 2) + (Remainder / 2));
}