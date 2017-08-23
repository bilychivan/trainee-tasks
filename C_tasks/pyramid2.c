/*
Задача pyramid2

Условие задачи
Вывести числовую пирамидку на total строк.
В первой строке стоит число 1. В последующих строках стоят увеличивающиеся числа
через пробел.

Пример ввода
3
Пример вывода
1
2 3
4 5 6

*/

#include "stdio.h"

int main()
{
	unsigned int total;
	unsigned int value = 1u;

	scanf("%u", &total);

	for (unsigned int i = 0u; i < total; ++i)
	{
		for (unsigned int j = 0u; j < i; ++j)
		{
			printf("%u ", value++);
		}
		printf("%u\n", value++);
	}

	return 0;
}