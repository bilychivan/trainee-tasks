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

unsigned int average(unsigned int a, unsigned int b)
{
	return ((a+b) / 2);
}

int main()
{
	printf("Average of 4 and 5 is: %u\n", average(4, 5));
	return 0;
}