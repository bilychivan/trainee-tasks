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
    FILE* inputFile;
    FILE* outputFile;
    unsigned int inputLength;

    inputFile = fopen("abs.in", "r");

    fscanf(inputFile, "%d", &inputLength);

    int inputNumbers[inputLength];

    for (unsigned int i = 0; i < inputLength; i++)
    {
        fscanf(inputFile, "%d", &inputNumbers[i]);

        if (inputNumbers[i] < 0)
        {
            inputNumbers[i] *= -1;
        }
    }

    fclose(inputFile);

    outputFile = fopen("abs.out", "w");

    inputLength--;
    for (unsigned int i = 0; i < inputLength; i++)
    {
        fprintf(outputFile, "%d ", inputNumbers[i]);
    }
    fprintf(outputFile, "%d\n", inputNumbers[inputLength]);

    fclose(outputFile);

    return 0;
}