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

void arrayExchange(int array[], int len)
{
    len -= 2;
    for (int i = 0; i < len; i += 2)
    {
        int temp     = array[i];
        array[i]     = array[i + 1];
        array[i + 1] = temp;
    }

    if ((len % 2) == 0)
    {
        int temp       = array[len];
        array[len]     = array[len + 1];
        array[len + 1] = temp;
    }
}

void test(int array[], int len)
{
    arrayExchange(array, len);
    for (unsigned int i = 0; i < len; i++)
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