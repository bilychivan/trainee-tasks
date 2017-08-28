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
    int *array_head = &array[0];
    int *array_offset = &array[1];
    int *boundary = &array[size - 1];
    int temp = array[0];

    for (; array_head < boundary; ++array_head, ++array_offset)
    {
        *array_head = *array_offset;
    }

    array[size - 1] = temp;
}