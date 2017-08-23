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