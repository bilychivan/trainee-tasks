/*
Задача square1

Условие задачи
Вывести числовой квадрат заданного размера.
В каждой строке числа идут с единицы через пробел.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
1 2
1 2

*/

#include <stdio.h>

int main()
{
    unsigned int size;

    scanf("%d", &size);

    for (unsigned int i = 0; i < size; i++)
    {
        for (unsigned int j = 1; j < size; j++)
        {
            printf("%d ", j);
        }

        printf("%d\n", size);
    }

    return 0;
}