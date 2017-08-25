/*
Задача pyramid

Условие задачи
Вывести в консоль числовую пирамидку на total строк.
В каждой строке числа идут от единицы до номера строки через пробел.
Пропустить rows строк и cols столбцов.
В выводе не должно быть пустых строк до и после чисел.
Целые положительные числа total, rows и cols считать с клавиатуры.

Пример ввода
5 3 2
Пример вывода
3 4
3 4 5

*/

#include <stdio.h>

int main()
{
    unsigned int total;
    unsigned int rows, cols;

    scanf("%d %d %d", &total, &rows, &cols);

    if (cols > rows)
    {
        rows = cols;
    }

    for (unsigned int i = rows + 1; i <= total; i++)
    {
        unsigned int max = i - 1;

        for (unsigned int j = cols; j < max; j++)
        {
            printf("%d ", j + 1);
        }

        printf("%d\n", max + 1);
    }

    return 0;
}