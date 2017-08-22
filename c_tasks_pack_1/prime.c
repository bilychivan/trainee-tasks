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

    int prime = 1;
    for (int i = 3; i < n; i += 2)
    {
        double t = (double)n / (double)i;
        if ((t - (int)t) == 0)
        {
            prime = 0;
            break;
        }
    }
    return prime;
}

int main()
{
    unsigned int target;
    scanf("%u", &target);
    if (target == 1)
    {
        puts("2");
        return 0;
    }

    unsigned int current = 1;
    for (int i = 3;; i+=2)
    {
        if (isPrime(i))
        {
            current++;

            if (current == target)
            {
                printf("%i", i);
                break;
            }
        }
    }
    return 0;
}
