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

int arrayUnique(int array[], int size)
{
    unsigned int j;
    int newSize = 1;

    for(unsigned int i = 1; i < size; i++)
    {
        for(j = 0; j < newSize; j++)
        {
            if(array[i] == array[j])
            {
                j = newSize + 1;
            }
        }

        if (j == newSize)
        {
            array[newSize++] = array[i];
        }
    }

    return newSize;
}