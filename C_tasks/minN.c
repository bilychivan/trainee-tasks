/*
Задача minN

Условие задачи
Считать с клавиатуры целое положительное число - количество чисел в
последовательности.
Затем считать с клавиатуры заданное количество чисел и вывести наименьшее из
них.
Данная задача решается без массивов.

Пример ввода
5
1 2 3 4 5
Пример вывода
1

*/

#include "stdio.h"

int main()
{
	unsigned int quantity;
	int min, input_value;

	scanf("%u %d", &quantity, &min);

	while (--quantity)
	{
		scanf("%d", &input_value);

		if (min > input_value)
			min = input_value;
	}

	printf("%d\n", min);

	return 0;
}