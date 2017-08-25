/*
Задача square2

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
1 2
3 4

*/

#include <stdio.h>

int main()
{
    unsigned int size;

    scanf("%d", &size);

    for (unsigned int i = 0, counter = 1; i < size; i++)
    {
        for (unsigned int j = 1; j < size; j++)
        {
            printf("%d ", counter++);
        }

        printf("%d\n", counter++);
    }

    return 0;
}