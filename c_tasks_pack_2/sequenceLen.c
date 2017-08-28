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

unsigned int proccessInputFile()
{
    const int maxDataLength = 100;
    unsigned int length = 0;

    FILE* inputFile = fopen("task.in", "r");

    for (int inputNumber = 0; (fscanf(inputFile, "%d", &inputNumber) > 0) && (length < maxDataLength); length++);

    fclose(inputFile);

    return length;
}

void writeOutputFile(unsigned int length)
{
    FILE* outputFile = fopen("task.out", "w");

    fprintf(outputFile, "%d", length);

    fclose(outputFile);
}

int main()
{
    unsigned int length = proccessInputFile();

    writeOutputFile(length);

    return 0;
}