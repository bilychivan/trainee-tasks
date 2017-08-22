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
    unsigned int target;
    scanf("%d", &target);
    if (target < 1)
    {
        printf("-1\n");
    }
    if (target == 1)
    {
        printf("2\n");
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
                printf("%i\n", i);
                break;
            }
        }
    }
    return 0;
}
