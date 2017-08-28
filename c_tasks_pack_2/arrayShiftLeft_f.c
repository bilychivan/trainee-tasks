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
    for (int i = 1; i < size; i++)
    {
        int temp = array[i - 1];
        array[i - 1] = array[i];
        array[i] = temp;
    }
}

void test(int array[], int size)
{
    arrayShiftLeft(array, size);
    for (unsigned int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array1[] = {1};
    int array2[] = {1, 2};
    int array3[] = {1, 2, 3};
    int array4[] = {1, 2, 3, 4};
    int array5[] = {1, 2, 3, 4, 5};
    test(array1, 1);
    test(array2, 2);
    test(array3, 3);
    test(array4, 4);
    test(array5, 5);

    return 0;
}