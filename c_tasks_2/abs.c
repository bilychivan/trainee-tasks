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

int readLength(FILE* ptrFile)
{
    unsigned int length;

    fscanf(ptrFile, "%u", &length);

    return length;
}

void readArray(FILE* ptrFile, int array[], unsigned int len)
{
    for (unsigned int i = 0u; i < len; ++i)
    {
        fscanf(ptrFile, "%d", array + i);
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

void printArrayInFile(FILE* ptrFile, const int array[], unsigned int len)
{
    unsigned int max = len - 1u;
    for (unsigned int i = 0u; i < max; ++i)
    {
        fprintf(ptrFile, "%d ", array[i]);
    }
    fprintf(ptrFile, "%d\n", array[max]);
}

int main()
{
    FILE* pFile = fopen("task.in", "r");
    const unsigned int length = readLength(pFile);
    int numbers[length];

    readArray(pFile, numbers, length);
    absArray(numbers, length);

    fclose(pFile);
    pFile = fopen("task.out", "w");

    printArrayInFile(pFile, numbers, length);

    fclose(pFile);

    return 0;
}