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

void strReverse(char* low, char* high)
{
    for (; low < high; low++, high--)
    {
        char temp = *low;
        *low = *high;
        *high = temp;
    }
}

int main()
{
    FILE* inputFile;
    FILE* outputFile;
    unsigned int inputLength;
    const int maxInputLength = 100;
    char inputChars[maxInputLength];

    inputFile = fopen("task.in", "r");

    for (inputLength = 0; (fscanf(inputFile, "%c", &inputChars[inputLength]) > 0) && (inputLength < maxInputLength); inputLength++);

    fclose(inputFile);

    strReverse(&inputChars[0], &inputChars[inputLength - 1]);

    outputFile = fopen("task.out", "w");

    fwrite(&inputChars, inputLength, 1, inputFile);

    fclose(outputFile);

    return 0;
}