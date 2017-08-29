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

const char FILENAME_INPUT[]  = "task.in";
const char FILENAME_OUTPUT[] = "task.out";

const int MAXIMUM_INPUT_LENGTH = 100;

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
    char inputChars[MAXIMUM_INPUT_LENGTH];

    inputFile = fopen(FILENAME_INPUT, "r");

    for (inputLength = 0; (fscanf(inputFile, "%c", &inputChars[inputLength]) > 0) && (inputLength < 100); inputLength++);

    fclose(inputFile);

    strReverse(&inputChars[0], &inputChars[inputLength - 1]);

    outputFile = fopen(FILENAME_OUTPUT, "w");

    fwrite(&inputChars, inputLength, 1, inputFile);

    fclose(outputFile);

    return 0;
}