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
        char temp = *low;
        *low      = *high;
        *high     = temp;
    }
}

void test(int array[], int lo, int hi, int len)
{
    sliceReverse(array, lo, hi);
    for (unsigned int i = 0; i < len; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    test(array1, 2, 7, 10);

    return 0;
}