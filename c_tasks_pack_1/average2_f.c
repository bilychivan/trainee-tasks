/*
Задача average2()

Условие задачи
int average(int a, int b)
Вернуть среднее арифметическое двух целых чисел. Использовать только тип int.
Если среднее значение не является целым, то округлить его к ближайшему целому в
сторону нуля.

*/

#include <stdio.h>

int average(int a, int b)
{
	return ((a+b) / 2);
}

int main()
{
	printf("Average of 3 and 4 is: %i\n", average(3, 4));
	return 0;
}