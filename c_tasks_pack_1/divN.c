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
    int start, max;
    unsigned divisor;

    scanf("%d %d %u", &start, &max, &divisor);

    if ((start % divisor) != 0)
    {
        start = start - start % divisor + divisor;
    }

    for ( ; start <= max; start += divisor)
    {
        printf("%d\n", start);
    }

    return 0;
}
