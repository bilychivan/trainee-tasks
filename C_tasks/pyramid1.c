/*
Задача pyramid1

Условие задачи
Вывести числовую пирамидку на total строк.
В каждой строке числа идут от единицы до номера строки через пробел.

Пример ввода
3
Пример вывода
1
1 2
1 2 3

*/

#include "stdio.h"

int main()
{
	unsigned int total;

	scanf("%u", &total);

	for (unsigned int i = 1; i <= total; ++i)
	{
		for (unsigned int j = 1; j < i; ++j)
		{
			printf("%u ", j);
		}
		printf("%u\n", i);
	}

	return 0;
}