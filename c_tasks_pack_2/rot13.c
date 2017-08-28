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

#define ROT 13
#define FILEIN "task.in"
#define FILEOUT "task.out"
#define STR_LEN 100

int rotF(char c)
{
    if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
    {
        c += ROT;
    }
    else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
    {
        c -= ROT;
    }

    return c;
}

int main(void)
{
    FILE *fileIn = fopen(FILEIN, "r");
    FILE *fileOut = fopen(FILEOUT, "w");
    char str[STR_LEN + 1] = {0};
    char c;

    for (int i = 0; fscanf(fileIn,"%c", &c) != EOF && i < STR_LEN; i++)
    {
        str[i] = rotF(c);
    }
    fclose(fileIn);

    fprintf(fileOut, "%s\n", str);
    fclose(fileOut);

    return 0;
}