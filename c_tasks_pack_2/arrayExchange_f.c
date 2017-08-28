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

void arrayExchange(int array[], int len)
{
    int  boundary = len - 1;
    int *array_offset = &array[0] + 1;

    for (int i = 0; i < boundary; i += 2)
    {
        int temp = array[i];
        array[i] = array_offset[i];
        array_offset[i] = temp;
    }
}