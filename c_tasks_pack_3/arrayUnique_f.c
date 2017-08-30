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

#define TRUE 1
#define FALSE 0

int areUnique(int array[], int size, int pos)
{
    int unique = array[pos];

    for (int i = 0; i < pos; i++)
    {
        if (array[i] == unique)
        {
            return FALSE;
        }
    }

    return TRUE;
}

int arrayUnique(int array[], int size)
{
    int pos = 0;

    for (int i = 0; i < size; i++)
    {
        if (areUnique(array, size, i))
        {
            array[pos] = array[i];
            pos += 1;
        }
    }

    return pos;
}

int main(void)
{
    int array[25] = {1 ,1 ,2 ,2 ,3 ,3 ,4 ,4 ,5 ,5 ,6 ,6 ,7 ,7 ,8 ,8 ,9 ,9 ,10 ,10 ,5 ,4 ,3 ,2, 1};
    int size = arrayUnique(array, 25) - 1;
    int i = 0;

    for (; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("%d/n", array[i]);

    return 0;
}