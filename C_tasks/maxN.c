/*
Задача maxN

Условие задачи
Считать с клавиатуры целое положительное число - количество чисел в
последовательности.
Затем считать с клавиатуры заданное количество чисел и вывести наибольшее из
них.
Данная задача решается без массивов.

Пример ввода
5
1 2 3 4 5
Пример вывода
5

*/

#include "stdio.h"

int main()
{
	unsigned int quantity;
	int max, input_value;

	scanf("%u %d", &quantity, &max);

	while (--quantity)
	{
		scanf("%d", &input_value);

		if (max < input_value)
			max = input_value;
	}

	printf("%d\n", max);

	return 0;
}