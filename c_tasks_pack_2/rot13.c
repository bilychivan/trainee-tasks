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

unsigned char applyRot13(unsigned char ch)
{
    const int rotateNumber = 13;
    const int alphabetSize = 26;

    if ((ch >= 'A') && (ch <= 'Z'))
    {
        ch += rotateNumber;
        if (ch > 'Z')
        {
            ch -= alphabetSize;
        }
    }
    else
    {
        ch += rotateNumber;
        if (ch > 'z')
        {
            ch -= alphabetSize;
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

    inputFile  = fopen("task.in" , "r");
    outputFile = fopen("task.out", "w");

    for (counter = 0; (fscanf(inputFile, "%c", &inputChar) > 0) && (counter < 100); counter++)
    {
        fprintf(outputFile, "%c", applyRot13(inputChar));
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}