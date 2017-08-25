/*
Задача pyramid2

Условие задачи
Вывести числовую пирамидку на total строк.
В первой строке стоит число 1. В последующих строках стоят увеличивающиеся числа
через пробел.

Пример ввода
3
Пример вывода
1
2 3
4 5 6

*/

#include <stdio.h>

int main()
{
    unsigned int total;

    scanf("%d", &total);

    for (unsigned int i = 1, counter = 1; i <= total; i++)
    {
        unsigned int max = i - 1;

        for (unsigned int j = 0; j < max; j++)
        {
            printf("%d ", counter++);
        }

        printf("%d\n", counter++);
    }

    return 0;
}