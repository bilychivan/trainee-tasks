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

#define ROT 13
#define FILEIN "task.in"
#define FILEOUT "task.out"
#define STR_LEN 100

void sliceReverse(char array[], int lo, int hi)
{
    char swap;

    for (; lo < hi; lo++, hi--)
    {
        swap = array[hi];
        array[hi] = array[lo];
        array[lo] = swap;
    }
}

int strlenF(char *src)
{
    int len = 0;

    for (; src[len]; len++) {}

    return len;
}

int main(void)
{
    FILE *fileIn = fopen(FILEIN, "r");
    FILE *fileOut = fopen(FILEOUT, "w");
    char str[STR_LEN + 1] = {0};

    fscanf(fileIn, "%100c", str);
    fclose(fileIn);

    sliceReverse(str, 0, strlenF(str) - 1);

    fprintf(fileOut, "%s\n", str);
    fclose(fileOut);

    return 0;
}