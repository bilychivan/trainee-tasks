/*
Задача arrayShift()

Условие задачи
Написать функцию:
void arrayShift(int array[], int size, int shift)
Реализовать циклический сдвиг массива на shift элементов вправо. Максимизировать
производительность при оптимальном использовании памяти.
Требуемая сложность: O(N)

*/

void arrayShift(int array[], int size, int shift)
{
    int temp[shift];
    int *shifted_array = array + size - shift;

    for (int i = 0, offset = size - shift; i < shift; ++i)
    {
        temp[i] = shifted_array[i];
    }

    shifted_array = array - shift;

    for (int i = size - 1; i >= shift; --i)
    {
        array[i] = shifted_array[i];
    }

    for (int i = 0; i < shift; ++i)
    {
        array[i] = temp[i];
    }
}