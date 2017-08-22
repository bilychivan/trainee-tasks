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
    // source:
    // http://www.hackersdelight.org/basics2.pdf
    // Page 19, paragraph 2-5
    int t = (a & b) + ((a ^ b) >> 1);
    unsigned t_u = (unsigned)t;
    return (t + ((t_u >> 31) & (a ^ b)));
}

int main()
{
    printf("Average of -10 and   5 is (should  -2): %d\n", average(-10, 5));
	printf("Average of   6 and  15 is (should  10): %d\n", average(6, 15));
	printf("Average of   6 and -15 is (should  -4): %d\n", average(6, -15));
	printf("Average of  -6 and -15 is (should -10): %d\n", average(-6, -15));

	return 0;
}
