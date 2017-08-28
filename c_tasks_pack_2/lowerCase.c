/*
Задача lowerCase

Условие задачи
В файле task.in дана последовательность символов.
Перевести все буквы в нижний регистр и вывести результирующую последовательность
в файл task.out

Пример ввода
ABCD
Пример вывода
abcd

*/

#include <stdio.h>

int main()
{
    const int TO_UPPER = 32;
    FILE* inputFile;
    FILE* outputFile;
    unsigned int inputLength;

    inputFile = fopen("lowerCase.in", "r");

    fseek(inputFile, 0, SEEK_END);
    inputLength = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    char inputChars[inputLength];

    fread(&inputChars, inputLength, 1, inputFile);

    for (unsigned int i = 0; i < inputLength; i++)
    {
        inputChars[i] += TO_UPPER;
    }

    fclose(inputFile);


    outputFile = fopen("lowerCase.out", "w");

    fwrite(&inputChars, inputLength, 1, inputFile);

    fclose(outputFile);

    return 0;
}