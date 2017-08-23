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
	scanf("%u", &total);

	for (int i = 0, value = 1; i < total; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			printf("%u ", value++);
		}
		printf("\b\n");
	}

	return 0;
}