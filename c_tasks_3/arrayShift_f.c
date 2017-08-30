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

#define SIZE 10

void arrayShift(int array[], int size, int shift)
{
    if (shift < 0)
    {
        shift += size;
    }

    shift %= size;

    int temp[shift];

    for (int i = 0, j = size - shift; i < shift; ++i, ++j)
    {
        temp[i] = array[j];
    }

    for (int i = size - 1, j = i - shift; i >= shift; --i, --j)
    {
        array[i] = array[j];
    }

    for (int i = 0; i < shift; ++i)
    {
        array[i] = temp[i];
    }
}

void display(const int array[], int len)
{
    if (len < 1)
    {
        printf("\n");

        return;
    }

    int size = len - 1;

    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[size]);
}

void test(int array[], int size, int shift)
{
    display(array, size);

    arrayShift(array, size, shift);

    display(array, size);

    printf("--------------------\n");
}

int main()
{
    int numbers[] =
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    test(numbers, SIZE, 1);
    test(numbers, SIZE, 2);
    test(numbers, SIZE, 3);
    test(numbers, SIZE, 12);
    test(numbers, SIZE, -1);

    return 0;
}