/*
Задача square2rev

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Порядок строк обратный.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
3 4
1 2

*/

#include "stdio.h"

int main()
{
	unsigned int size;
	unsigned int first_in_row;

	scanf("%u", &size);

	first_in_row = size * (size - 1);

	for (int i = 0; i < size; ++i)
	{
		for (int j = 1; j < size; ++j)
		{
			printf("%u ", first_in_row + j);
		}
		printf("%u\n", first_in_row + size);

		first_in_row -= size;
	}

	return 0;
}