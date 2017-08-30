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
    int *shifted_array = &array[-shift];

    for (int *temp_a = &temp[shift - 1], *temp_b = &array[size - 1]; temp_a >= temp; *temp_a-- = *temp_b--);

    for (unsigned int i = size - 1; i >= shift; i--)
    {
        array[i] = shifted_array[i];
    }

    for (unsigned int i = 0; i < shift; i++)
    {
        array[i] = temp[i];
    }
}