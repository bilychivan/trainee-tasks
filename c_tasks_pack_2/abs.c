/*
Задача abs

Условие задачи
В файле task.in дана длина последовательности чисел (число больше нуля) и сама
последовательность.
Прочитать последовательность в массив.
Найти все отрицательные числа и заменить их положительными, равными по модулю.
Результирующий массив вывести в task.out.

Пример ввода
10
10 -20 30 40 -50 -60 70 80 90 -100
Пример вывода
10 20 30 40 50 60 70 80 90 100

*/

#include <stdio.h>

int absF(int n)
{
    if (n < 0)
    {
        return n * -1;
    }

    return n;
}

int strlenScanf(FILE *fileIn)
{
    int len;

    fscanf(fileIn,"%d", &len);

    return len;
}

void scanArr(FILE *fileIn, int array[], int len)
{
    for (int count = 0; count < len; count++)
    {
        fscanf(fileIn,"%d", &array[count]);
    }
}

void arrayAbs(int array[], int len)
{
    for (int count = 0; count < len; count++)
    {
        array[count] = absF(array[count]);
    }
}

void printArr(FILE *fileOut, int array[], int len)
{
    int count;

    for (count = 0; count < len; count++)
    {
        fprintf(fileOut, "%d ", array[count]);
    }
    fprintf(fileOut, "%d\n", array[count]);
}

int main(void)
{
    FILE *fileIn = fopen("task.in", "r");
    FILE *fileOut = fopen("task.out", "w");
    int len = strlenScanf(fileIn);
    int array[len];

    scanArr(fileIn, array, len);
    fclose(fileIn);

    arrayAbs(array, len);

    printArr(fileOut, array, len - 1);
    fclose(fileOut);

    return 0;
}