/*
Задача nextMultiple

Условие задачи
Считать с клавиатуры два целых числа - делимое и делитель, причем делитель не равен нулю.
Вывести на экран наименьшее число, кратное делителю, не меньшее делимого.
Пример ввода
15 6
Пример вывода
18

*/

#include <stdio.h>

int main()
{
    int dividend, divider;

    scanf("%d %d", &dividend, &divider);

    if ((dividend % divider) != 0)
    {
        if (divider < 0)
        {
            divider *= -1;
        }
        printf("%i\n", (dividend / divider) * divider + divider);
    }
    else
    {
        printf("%i\n", dividend);
    }

    return 0;
}
