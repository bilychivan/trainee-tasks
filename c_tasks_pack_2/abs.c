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

#define FILEIN "task.in"
#define FILEOUT "task.out"

int abs_f(int n)
{
    if (n < 0)
    {
        return n * -1;
    }

    return n;
}

int main(void)
{
    FILE *fileIn, *fileOut;
    int len;
    int count;

    if ((fileIn = fopen(FILEIN, "r")) == NULL)
    {
        return 1;
    }
    if ((fileOut = fopen(FILEOUT, "w")) == NULL)
    {
        return 1;
    }
    
    fscanf(fileIn,"%d", &len);

    int arr[len];

    for (count = 0; count < len - 1; count++)
    {
        fscanf(fileIn,"%d", &arr[count]);
        arr[count] = abs_f(arr[count]);
        fprintf(fileOut, "%d ", arr[count]);
    }
    fscanf(fileIn,"%d", &arr[count]);
    arr[count] = abs_f(arr[count]);
    fprintf(fileOut, "%d\n", arr[count]);

    fclose(fileIn);
    fclose(fileOut);

    return 0;
}