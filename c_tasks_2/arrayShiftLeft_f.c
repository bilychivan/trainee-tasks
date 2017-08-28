/*
Задача arrayShiftLeft()

Условие задачи
Написать функцию:
arrayShiftLeft(int array[], int size)

Реализовать циклический сдвиг массива на 1 элемент влево.
Использование дополнительного массива не разрешается.

*/

#include <stdio.h>

void arrayShiftLeft(int array[], int size)
{
    int temp = array[0];

    for (int i = 1; i < size; ++i)
    {
        array[i - 1] = array[i];
    }

    array[size - 1] = temp;
}

void displayArray(const int array[], int len)
{
    int size = len - 1;

    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[size]);
}

void testArray(int array[], int len)
{
    printf("Before: ");
    displayArray(array, len);

    arrayShiftLeft(array, len);

    printf("After: ");
    displayArray(array, len);
}

int main()
{
    int numbers[] =
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    testArray(numbers, 3);
    testArray(numbers, 8);
    testArray(numbers, 10);

    return 0;
}