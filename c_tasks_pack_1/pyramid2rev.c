/*
Задача pyramid2rev

Условие задачи
Вывести числовую пирамидку на total строк. Порядок строк – обратный.
В первой строке стоит число 1. В последующих строках стоят увеличивающиеся числа
через пробел.

Пример ввода
3
Пример вывода
4 5 6
2 3
1

*/

#include <stdio.h>

int main()
{
    unsigned int total;

    scanf("%d", &total);

    for (unsigned int i = total, counter = total * total / 2 + total / 2 + total % 2; i > 0; i--)
    {
        unsigned int max = i - 1;

        for (unsigned int j = max; j > 0; j--)
        {
            printf("%d ", counter--);
        }

        printf("%d\n", counter--);
    }

    return 0;
}