/*
Задача divN

Условие задачи
Считать с клавиатуры целые числа min, max и положительный делитель. Вывести в столбик числа, кратные делителю, от min до max включительно.

Пример ввода
0 8 2
Пример вывода
0
2
4
6
8

*/

#include <stdio.h>

int main()
{
    int start, max, divisor;
    scanf("%d %d %d", &start, &max, &divisor);

    for ( ; start <= max; start++)
    {
        if ((start % divisor) == 0)
        {
            printf("%d\n", start);
        }
    }
    return 0;
}
