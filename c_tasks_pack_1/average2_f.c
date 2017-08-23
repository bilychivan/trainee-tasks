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
	return (int)((double)a / 2 + (double)b / 2);
}

int main()
{
	printf("Average of 3 and 4 is: %i\n", average(2147483647, 2147483647));
	return 0;
}
