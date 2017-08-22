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
	return (unsigned int)((double)a / 2 + (double)b / 2);
}

int main()
{
	printf("Average of 4 and 5 is: %u\n", average(4294967295, 4294967295));
	return 0;
}
