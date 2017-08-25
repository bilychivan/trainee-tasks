/*
Задача square2rev

Условие задачи
Вывести числовой квадрат заданного размера.
Выведенные числа начинаются с единицы и постоянно увеличиваются.
В каждой строке числа разделены пробелами.
Порядок строк обратный.
Размер считать с клавиатуры.

Пример ввода
2
Пример вывода
3 4
1 2

*/

#include <stdio.h>

int main()
{
    unsigned int size;

    scanf("%d", &size);

    for (unsigned int i = 0, counter = size * size; i < size; i++)
    {
        counter = counter - size + 1;

        for (unsigned int j = 1; j < size; j++)
        {
            printf("%d ", counter++);
        }

        printf("%d\n", counter++);

        counter = counter - size - 1;
    }

    return 0;
}