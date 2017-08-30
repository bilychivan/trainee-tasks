/*
Задача arrayShift()

Условие задачи
Написать функцию:
void arrayShift(int array[], int size, int shift)
Реализовать циклический сдвиг массива на shift элементов вправо. Максимизировать
производительность при оптимальном использовании памяти.
Требуемая сложность: O(N)

*/

#include <stdio.h>

int abs(int n)
{
    if (n < 0)
    {
        return n * -1;
    }

    return n;
}

void arrayShift(int array[], int size, int shift)
{
    int res[abs(shift)];
    int lastPos = size - 1;
    int i;

    if (shift >= 0)
    {
        for (int j = 0; j < shift; j++)
        {
            int i = (size - (shift - j));
            res[j] = array[i];
        }
        for (i = lastPos; i >= shift; i--)
        {
            int j = i - shift;
            array[i] = array[j];
        }
        for (int k = 0; k < shift ; k++)
        {
            array[k] = res[k];
        }
    }
    else
    {
        int newShift = shift * -1;
        int remainderN = size - newShift;

        for (int j = 0; j < newShift; j++)
        {
            res[j] = array[j];
        }
        for (i = 0; i < remainderN; i++)
        {
            int j = i + newShift;
            array[i] = array[j];
        }
        for (int k = 0; i < size ; i++, k++)
        {
            array[i] = res[k];
        }
    }
}

int main(void)
{
    int array[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    arrayShift(array, 12, 3);
    for (int i = 0; i < 12; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}