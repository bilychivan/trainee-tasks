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

int isPrime(int n)
{
	if (n == 2)
	{
		return 1;
	}
	else if (n < 2 || n % 2 == 0)
	{
		return 0;
	}

	for (int i = 3; i < n / 2; i += 2)
	{
		if (n % i == 0)
			return 0;
	}

	return 1;
}

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