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
    for ( ; lo <= hi; lo++, hi--)
    {
        array[lo] += array[hi];
        array[hi] = array[lo] - array[hi];
        array[lo] -= array[hi];
    }
}

void displayArray(const int array[], int len)
{
    int max = len - 1;
    for (int i = 0; i < max; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[max]);
}

void testArray(int array[], int len, int lo, int hi)
{
    printf("Before: ");
    displayArray(array, len);

    sliceReverse(array, lo, hi);

    printf("After: ");
    displayArray(array, len);
}

int main()
{
    int numbers[] =
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    testArray(numbers, 10, 0, 9);
    testArray(numbers, 8, 3, 7);
    testArray(numbers, 5, 5, 9);

    return 0;
}