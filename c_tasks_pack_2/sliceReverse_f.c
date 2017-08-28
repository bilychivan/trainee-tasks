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
    int swap;

    for (; lo < hi; lo++, hi--)
    {
        swap = array[hi];
        array[hi] = array[lo];
        array[lo] = swap;
    }
}

int main(void)
{
    int array[10] = {0,1,2,3,4,5,6,7,8,9};

    sliceReverse(array, 2, 6);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}