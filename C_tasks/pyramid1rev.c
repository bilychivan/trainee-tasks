/*
Задача pyramid1rev

Условие задачи
Вывести числовую пирамидку на total строк. Порядок строк – обратный.
В каждой строке числа идут от единицы до номера строки через пробел.

Пример ввода
3
Пример вывода
1 2 3
1 2
1

*/

#include "stdio.h"

int main()
{
	unsigned int total;
	scanf("%u", &total);

	for (unsigned int i = 0; i < total; ++i)
	{
		for (unsigned int j = 1; j <= total - i; ++j)
		{
			printf("%u ", j);
		}
		printf("\b\n");
	}

	return 0;
}