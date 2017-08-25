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

#include <stdio.h>

int main()
{
    unsigned int total;

    scanf("%d", &total);

    for (unsigned int i = total; i > 0; i--)
    {
        unsigned int max = i - 1;

        for (unsigned int j = max; j > 0; j--)
        {
            printf("%d ", i - j);
        }

        printf("%d\n", i);
    }

    return 0;
}