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

const char FILENAME_INPUT[]    = "task.in";
const char FILENAME_OUTPUT[]   = "task.out";
const int  MAXIMUM_DATA_LENGTH = 100;

struct inputData
{
    unsigned int counter;
};
typedef struct inputData inputData;

inputData proccessInputFile()
{
    inputData data = {0};
    FILE* inputFile = fopen(FILENAME_INPUT, "r");

    for (int inputNumber = 0; (fscanf(inputFile, "%d", &inputNumber) > 0) && (data.counter < MAXIMUM_DATA_LENGTH); data.counter++);

    fclose(inputFile);

    return data;
}

void writeOutputFile(inputData data)
{
    FILE* outputFile = fopen(FILENAME_OUTPUT, "w");

    fprintf(outputFile, "%d", data.counter);

    fclose(outputFile);
}

int main()
{
    inputData data = proccessInputFile();

    writeOutputFile(data);

    return 0;
}