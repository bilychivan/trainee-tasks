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

const char FILENAME_INPUT[]  = "task.in";
const char FILENAME_OUTPUT[] = "task.out";

int readInputSize(FILE* inputFile)
{
    int temp;
    fscanf(inputFile, "%d", &temp);
    return temp;
}

void processInput(FILE* inputFile, int inputLength, int inputNumbers[])
{
    for (int i = 0; i < inputLength; i++)
    {
        fscanf(inputFile, "%d", &inputNumbers[i]);

        if (inputNumbers[i] < 0)
        {
            inputNumbers[i] *= -1;
        }
    }
}

int main()
{
    FILE* inputFile = fopen(FILENAME_INPUT, "r");
    FILE* outputFile;
    int inputLength;

    inputLength = readInputSize(inputFile);

    int inputNumbers[inputLength];

    processInput(inputFile, inputLength, inputNumbers);

    fclose(inputFile);

    outputFile = fopen(FILENAME_OUTPUT, "w");

    int size = inputLength - 1;
    for (unsigned int i = 0; i < size; i++)
    {
        fprintf(outputFile, "%d ", inputNumbers[i]);
    }
    fprintf(outputFile, "%d\n", inputNumbers[size]);

    fclose(outputFile);

    return 0;
}