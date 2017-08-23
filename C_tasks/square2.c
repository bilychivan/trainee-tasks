/*
Задача square2

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
1 2
3 4

*/

#include "stdio.h"

int main()
{
	unsigned int size;
	unsigned int value = 1u;

	scanf("%u", &size);

	for (unsigned int i = 0u; i < size; ++i)
	{
		for (unsigned int j = 1u; j < size; ++j)
		{
			printf("%u ", value++);
		}
		printf("%u\n", value++);
	}

	return 0;
}