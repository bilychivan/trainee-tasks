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
    int min, max, dividor;
    scanf("%i %i %i", &min, &max, &dividor);

    while (min <= max)
    {
        ((min % dividor) == 0) && printf("%i\n", min);
        min++;
    }
	return 0;
}
