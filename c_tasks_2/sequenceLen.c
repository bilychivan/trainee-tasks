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
    FILE* InputFile = fopen("task.in", "r");
    FILE* OutputFile = fopen("task.out", "w");
    unsigned int length = 0u;

    for (int num; length < QUANTITY && fscanf(InputFile, "%d", &num) != EOF; )
    {
        length += 1u;
    }

    fclose(InputFile);

    fprintf(OutputFile, "%u\n", length);

    fclose(OutputFile);

    return 0;
}