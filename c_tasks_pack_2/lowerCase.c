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

const char FILENAME_INPUT[]  = "task.in";
const char FILENAME_OUTPUT[] = "task.out";

int main()
{
    const int TO_UPPER = 32;
    FILE* inputFile;
    FILE* outputFile;
    char inputChar;

    inputFile  = fopen(FILENAME_INPUT , "r");
    outputFile = fopen(FILENAME_OUTPUT, "w");

    for (; fscanf(inputFile, "%c", &inputChar) > 0; )
    {
        inputChar += TO_UPPER;
        fprintf(outputFile, "%c", inputChar);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}