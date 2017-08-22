/*
Задача countdown

Условие задачи
Считать с клавиатуры целое неотрицательное число.
Вывести в строку убывающий ряд чисел от заданного до нуля.

Пример ввода
7
Пример вывода
7 6 5 4 3 2 1 0

*/

#include <stdio.h>

int main()
{
	unsigned int number;
	scanf("%u", &number);
	
	printf("%u ", number);
	while (number > 0)
	{
		number--;
		printf("%u ", number);
	}
	
	return 0;
}