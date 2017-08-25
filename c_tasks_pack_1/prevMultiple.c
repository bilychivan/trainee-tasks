/*
Задача prevMultiple

Условие задачи
Считать с клавиатуры два целых числа - делимое и делитель, причем делитель не равен нулю.
Вывести на экран наибольшее число, кратное делителю, не превышающее делимое.

Пример ввода
15 6
Пример вывода
12

*/

#include <stdio.h>

int main()
{
    int dividend, divider;

    scanf("%d %d", &dividend, &divider);

    if ((dividend % divider) != 0)
    {
        if (dividend >= 0)
        {
            printf("%i\n", (dividend / divider) * divider);
        }
        else
        {
            printf("%i\n", (dividend / divider) * divider - divider);
        }
    }
    else
    {
        printf("%i\n", dividend);
    }

    return 0;
}
