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
    return c;
}

int main(void)
{
    FILE *fileIn = fopen(FILEIN, "r");
    FILE *fileOut = fopen(FILEOUT, "w");
    char c;

    for (; fscanf(fileIn,"%c", &c) != EOF;)
    {
        c = toLower(c);
        fprintf(fileOut, "%c", c);
    }
    fclose(fileIn);
    
    fprintf(fileOut, "\n");
    fclose(fileOut);

    return 0;
}