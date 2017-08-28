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

int main()
{
    FILE* inputFile;
    FILE* outputFile;
    int inputNumber;
    int counter;

    inputFile = fopen("sequenceLen.in", "r");

    for (counter = 0; fscanf(inputFile, "%d", &inputNumber) > 0; counter++);

    fclose(inputFile);


    outputFile = fopen("sequenceLen.out", "w");

    fprintf(inputFile, "%d", counter);

    fclose(outputFile);

    return 0;
}