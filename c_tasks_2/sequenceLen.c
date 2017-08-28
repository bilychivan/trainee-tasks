/*
Задача sequenceLen
Условие задачи
Считать из файла task.in последовательность чисел размером не более 100
элементов.
Посчитать длину последовательности и вывести ее в task.out.

Пример ввода
10 20 30 40 50 60 70 80 90 100
Пример вывода
10

*/

#include <stdio.h>

#define QUANTITY 100u

int main()
{
    FILE* pFile = fopen("task.in", "r");
    int num;
    unsigned int length = 0u;

    for (; length < QUANTITY && fscanf(pFile, "%d", &num) != EOF; )
    {
        length += 1u;
    }

    fclose(pFile);
    pFile = fopen("task.out", "w");

    fprintf(pFile, "%u\n", length);

    fclose(pFile);

    return 0;
}