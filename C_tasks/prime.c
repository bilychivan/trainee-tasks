/*
Задача prime

Условие задачи
Вывести N-ное по счёту простое число (см. Википедию).
N считать с клавиатуры.
Оптимизировать работу программы, насколько это возможно.
В случае неопределенности ответа вывести -1.

Пример ввода
3
Пример вывода
5

*/

#include "stdio.h"

int main()
{
	unsigned int N;
	int quantity = 0, result = -1;
	
	scanf("%u", &N);

	for (int i = 1; i > 0 && quantity < N; ++i)
	{
		if (isPrime(i))
		{
			quantity++;
			result = i;
		}
	}

	printf("%d\n", result);

	return 0;
}