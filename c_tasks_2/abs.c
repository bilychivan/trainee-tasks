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

int readLength(FILE* inputFile)
{
    unsigned int length;

    fscanf(inputFile, "%u", &length);

    return length;
}

void readArray(FILE* inputFile, int array[], unsigned int len)
{
    for (unsigned int i = 0u; i < len; ++i)
    {
        fscanf(inputFile, "%d", array + i);
    }
}

void absArray(int array[], unsigned int len)
{
    for (unsigned int i = 0u; i < len; ++i)
    {
        if (array[i] < 0)
        {
            array[i] *= -1;
        }
    }
}

void printArrayInFile(const int array[], unsigned int len)
{
    FILE* outputFile = fopen("task.out", "w");
    unsigned int size = len - 1u;

    for (unsigned int i = 0u; i < size; ++i)
    {
        fprintf(outputFile, "%d ", array[i]);
    }
    fprintf(outputFile, "%d\n", array[size]);

    fclose(outputFile);
}

int main()
{
    FILE* inputFile = fopen("task.in", "r");
    const unsigned int length = readLength(inputFile);
    int numbers[length];

    readArray(inputFile, numbers, length);

    fclose(inputFile);

    absArray(numbers, length);

    printArrayInFile(numbers, length);

    return 0;
}