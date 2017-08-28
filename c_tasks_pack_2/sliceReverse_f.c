/*
Задача sliceReverse()

Условие задачи
Написать функцию:
void sliceReverse(int array[], int lo, int hi)

Осуществить реверс части массива от lo до hi включительно.

*/

#include <stdio.h>

void sliceReverse(int array[], int lo, int hi)
{
    int* low  = &array[lo];
    int* high = &array[hi];

    for (; low < high; low++, high--)
    {
        int temp = *low;
        *low = *high;
        *high = temp;
    }
}