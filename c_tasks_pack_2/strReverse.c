/*
Задача strReverse

Условие задачи
В файле task.in дана строка длиной не более 100 символов.
Прочитать строку в память и произвести ее реверс.
Результат вывести в task.out.

Пример ввода
hello
Пример вывода
olleh

*/

#include <stdio.h>

int main()
{
    FILE* inputFile;
    FILE* outputFile;
    unsigned int inputLength;

    inputFile = fopen("strReverse.in", "r");

    fseek(inputFile, 0, SEEK_END);
    inputLength = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    char inputChars[inputLength];

    fread(&inputChars, inputLength, 1, inputFile);

    char* low  = &inputChars[0];
    char* high = &inputChars[inputLength - 1];

    for (; low < high; low++, high--)
    {
        char temp = *low;
        *low      = *high;
        *high     = temp;
    }

    fclose(inputFile);


    outputFile = fopen("strReverse.out", "w");

    fwrite(&inputChars, inputLength, 1, inputFile);

    fclose(outputFile);

    return 0;
}