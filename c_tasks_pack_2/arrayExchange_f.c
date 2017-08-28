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
    for ( int i = 0, j = 1; j < len; i += 2, j += 2 )
    {
        int temp = array[i];

        array[i] = array[j];
        array[j] = temp;
    }
}

int main(void)
{
    int array[9] = {0,1,2,3,4,5,6,7,8};

    arrayExchange(array, 9);

    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}