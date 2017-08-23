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
	int compared_value, input_value;

	scanf("%u %d", &quantity, &compared_value);

	while (--quantity)
	{
		scanf("%d", &input_value);

		if (compared_value > input_value)
		{
			compared_value = input_value;
		}
	}

	printf("%d\n", compared_value);

	return 0;
}