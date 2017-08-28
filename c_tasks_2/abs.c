/*
Задача abs

Условие задачи
В файле task.in дана длина последовательности чисел (число больше нуля) и сама
последовательность.
Прочитать последовательность в массив.
Найти все отрицательные числа и заменить их положительными, равными по модулю.
Результирующий массив вывести в task.out.

Пример ввода
10
10 -20 30 40 -50 -60 70 80 90 -100
Пример вывода
10 20 30 40 50 60 70 80 90 100

*/

#include <stdio.h>

int main()
{
    unsigned int length;
    unsigned int max;
    FILE* pFile = fopen("task.in", "r");

    fscanf(pFile, "%u", &length);

    int numbers[length];

    for (unsigned int i = 0u; i < length; ++i)
    {
        fscanf(pFile, "%d", numbers + i);

        if (numbers[i] < 0)
        {
            numbers[i] = -numbers[i];
        }
    }

    fclose(pFile);
    pFile = fopen("task.out", "w");

    max = length - 1u;
    for (unsigned int i = 0u; i < max; ++i)
    {
        fprintf(pFile, "%d ", numbers[i]);
    }
    fprintf(pFile, "%d\n", numbers[max]);

    fclose(pFile);

    return 0;
}