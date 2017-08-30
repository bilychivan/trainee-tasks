/*
Задача arrayUnique()

Условие задачи
Написать функцию:
int arrayUnique(int array[], int size)

Удалить из массива дубликаты элементов. Вернуть новую длину массива.

Примечание: пример ввода и вывода показан для лучшего понимания условия задачи.
Выводить результат на печать не нужно.

Пример ввода
1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 10 5 4 3 2 1
Пример вывода
array = 1 2 3 4 5 6 7 8 9 10
len = 10

*/

#include <stdio.h>

#define SIZE 17

int arrayUnique(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (array[i] == array[j])
            {
                for (int k = j, length = size - 1; k < length; ++k)
                {
                    array[k] = array[k + 1];
                }

                size -= 1;
                j -= 1;
            }
        }
    }

    return size;
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

void test(int array[], int size)
{
    printf("Before: size = %d\n", size);

    display(array, size);

    size = arrayUnique(array, size);

    printf("After: size = %d\n", size);

    display(array, size);

    printf("--------------------\n");
}

int main()
{
    int numbers[] =
    {
        1, 1, 7, 2, 2, 3, 3, 2, 1, 5, 5, 2, 2, 7, 1, 3, 1
    };

    test(numbers, SIZE);

    return 0;
}