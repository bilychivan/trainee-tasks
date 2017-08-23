/*
Задача multiple3
Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все числа, кратные 3, от нуля до указанного числа включительно.

Пример ввода
17
Пример вывода
0 3 6 9 12 15

*/

#include "stdio.h"

int main()
{
	unsigned int input_value;
	scanf("%u", &input_value);

	for (unsigned int i = 0; i <= input_value; i++)
	{
		if (i % 3u == 0u)
			printf("%u ", i);
	}
	printf("\b\n");

	return 0;
}