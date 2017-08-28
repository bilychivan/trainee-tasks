/*
Задача rot13

Условие задачи
Считать из файла task.in в память строку длиной не более 100 символов.
Зашифровать её по алгоритму ROT13.
Результат вывести в task.out.

Пример ввода
balk
Пример вывода
onyx

*/

#include <stdio.h>

const char FILENAME_INPUT[]  = "task.in";
const char FILENAME_OUTPUT[] = "task.out";

unsigned char applyRot13(unsigned char ch)
{
    const int ROTATE_NUMBER = 13;
    const int ALPHABET_SIZE = 26;

    if ((ch >= 'A') && (ch <= 'Z'))
    {
        ch += ROTATE_NUMBER;
        if (ch > 'Z')
        {
            ch -= ALPHABET_SIZE;
        }
    }
    else
    {
        ch += ROTATE_NUMBER;
        if (ch > 'z')
        {
            ch -= ALPHABET_SIZE;
        }
    }

    return ch;
}

int main()
{
    FILE* inputFile;
    FILE* outputFile;
    unsigned int counter;
    unsigned char inputChar;

    inputFile  = fopen(FILENAME_INPUT , "r");
    outputFile = fopen(FILENAME_OUTPUT, "w");

    for (counter = 0; (fscanf(inputFile, "%c", &inputChar) > 0) && (counter < 100); counter++)
    {
        fprintf(outputFile, "%c", applyRot13(inputChar));
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}