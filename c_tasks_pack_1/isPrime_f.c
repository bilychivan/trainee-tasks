/*
Задача isPrime()

Условие задачи
Написать функцию:
int isPrime(int n)

Проверить, является ли данное число простым.

*/

#include <stdio.h>
int isPrime(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    if ((n % 2) == 0)
    {
        return 0;
    }

    for (int i = 3; i < n; i += 2)
    {
        if ((n % i) == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
    return 0;
}
