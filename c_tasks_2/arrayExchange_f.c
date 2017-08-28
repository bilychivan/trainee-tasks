/*
Задача arrayExchange()

Условие задачи
Написать функцию
void arrayExchange(int array[], int len)

Попарно обменять местами все четные элементы массива с нечетными, начиная с
нулевого.
a[0] <-> a[1]   a[2] <-> a[3]   .....
Если последний элемент не имеет пары — не менять его значение.

Запрещено использование дополнительного массива.

*/

#include <stdio.h>

#define DIVISOR 2

void arrayExchange(int array[], int len)
{
    for (int i = 1; i < len; i += DIVISOR)
    {
        int temp = array[i];
        array[i] = array[i - 1];
        array[i - 1] = temp;
    }
}

void displayArray(const int array[], int len)
{
    int size = len - 1;

    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[size]);
}

void testArray(int array[], int len)
{
    printf("Before: ");
    displayArray(array, len);

    arrayExchange(array, len);

    printf("After: ");
    displayArray(array, len);
}

int main()
{
    int numbers[] =
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };

    testArray(numbers, 10);
    testArray(numbers, 8);
    testArray(numbers, 3);

    return 0;
}