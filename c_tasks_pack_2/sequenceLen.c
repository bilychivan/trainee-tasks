/*
Задача sequenceLen
Условие задачи
Считать из файла task.in последовательность чисел размером не более 100
элементов.
Посчитать длину последовательности и вывести ее в task.out.

Пример ввода
10 20 30 40 50 60 70 80 90 100
Пример вывода
10

*/

#include <stdio.h>

#define MAXLEN 100
#define FILEIN "task.in"
#define FILEOUT "task.out"

int main(void)
{
    FILE *fileIn = fopen(FILEIN, "r");
    FILE *fileOut = fopen(FILEOUT, "w");
    int len;
    int n;

    for (len = 0; fscanf(fileIn,"%d", &n) != EOF && len < MAXLEN; len++) {}
    fclose(fileIn);

    fprintf(fileOut, "%d\n", len);
    fclose(fileOut);

    return 0;
}