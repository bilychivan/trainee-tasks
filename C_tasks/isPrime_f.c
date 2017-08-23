/*
Задача isPrime()

Условие задачи
Написать функцию:
int isPrime(int n)

Проверить, является ли данное число простым.

*/

#include "stdio.h"

int isPrime(int n)
{
	int max = n / 2;
	
	if (n == 2)
	{
		return 1;
	}
	
	if (n < 2 || n % 2 == 0)
	{
		return 0;
	}

	for (int i = 3; i < max; i += 2)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	int input_value;

	scanf("%d", &input_value);

	if (isPrime(input_value))
	{
		printf("yes\n");
	}
	else
	{
		printf("no\n");
	}

	return 0;
}