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

#define SIZE1 17
#define SIZE2 10

int arrayUnique(int array[], int size)
{
    int k = 0;

    for (int i = 0, j; i < size; ++i)
    {
        for (j = i + 1; j < size && array[i] != array[j]; ++j);

        if (j == size)
        {
            array[k] = array[i];
            k += 1;
        }
    }

    return k;
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

    test(numbers, SIZE1);

    int numbers2[] =
    {
        6, 6, 1, 7, 6, 9, 0, 1, 2, 9
    };

    test(numbers2, SIZE2);

    return 0;
}