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
    const int toUpper = 32;
    char inputChar;
    FILE* inputFile = fopen("task.in" , "r");;
    FILE* outputFile = fopen("task.out", "w");

    for (; fscanf(inputFile, "%c", &inputChar) > 0; )
    {
        inputChar += toUpper;
        fprintf(outputFile, "%c", inputChar);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}