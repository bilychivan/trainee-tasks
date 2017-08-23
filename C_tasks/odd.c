/*
Задача odd

Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все нечётные числа от нуля до указанного числа включительно.

Пример ввода
9
Пример вывода
1 3 5 7 9

*/

#include "stdio.h"

int main()
{
	unsigned int input_value;
	scanf("%u", &input_value);

	for (unsigned int i = 1u; i <= input_value; i += 2)
	{
			printf("%u ", i);
	}
	printf("\b\n");

	return 0;
}