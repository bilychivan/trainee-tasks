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
    int sizeMax = size - 1;
    int counter;
    int swap = array[0];

    for (counter = 0; counter < sizeMax; counter++)
    {
        array[counter] = array[counter + 1];
    }
    array[counter] = swap;
}

int main(void)
{
    int array[9] = {12,1,2,3,4,5,6,7,8};

    arrayShiftLeft(array, 9);
    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}