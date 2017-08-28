/*
Задача arrayShiftLeft()

Условие задачи
Написать функцию:
arrayShiftLeft(int array[], int size)

Реализовать циклический сдвиг массива на 1 элемент влево.
Использование дополнительного массива не разрешается.

*/

void arrayShiftLeft(int array[], int size)
{
    int *array_head = &array[0];
    int *boundary = &array[size - 1];
    int temp = array[0];

    for (; array_head < boundary; ++array_head)
    {
        *array_head = array_head[1];
    }

    array[size - 1] = temp;
}