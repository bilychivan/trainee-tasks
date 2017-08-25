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

#include <stdio.h>

int main()
{
    unsigned int total;

    scanf("%d", &total);

    for (unsigned int i = 1; i <= total; i++)
    {
        unsigned int max = i - 1;

        for (unsigned int j = 0; j < max; j++)
        {
            printf("%d ", j + 1);
        }

        printf("%d\n", max + 1);
    }

    return 0;
}