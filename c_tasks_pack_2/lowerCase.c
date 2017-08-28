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

#define FILEIN "task.in"
#define FILEOUT "task.out"

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c += 32;
    }
    return (c);
}

int main(void)
{
    FILE *fileIn, *fileOut;
    char c;

    if ((fileIn = fopen(FILEIN, "r")) == NULL)
    {
        return 1;
    }
    if ((fileOut = fopen(FILEOUT, "w")) == NULL)
    {
        return 1;
    }

    for (; fscanf(fileIn,"%c", &c) != EOF;)
    {
        c = toLower(c);
        fprintf(fileOut, "%c", c);
    }
    fprintf(fileOut, "\n");

    fclose(fileIn);
    fclose(fileOut);

    return 0;
}