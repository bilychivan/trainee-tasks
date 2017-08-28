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

int rot_f(char c)
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
    FILE *fileIn, *fileOut;
    char str[STR_LEN + 1] = {0};
    char c;

    if ((fileIn = fopen(FILEIN, "r")) == NULL)
    {
        return 1;
    }
    if ((fileOut = fopen(FILEOUT, "w")) == NULL)
    {
        return 1;
    }

    for (int i = 0; fscanf(fileIn,"%c", &c) != EOF && i < STR_LEN; i++)
    {
        str[i] = rot_f(c);
    }
    fprintf(fileOut, "%s\n", str);

    fclose(fileIn);
    fclose(fileOut);

    return 0;
}