/*
Задача div2

Условие задачи
Считать min, max. Вывести в столбик чётные числа от min до max включительно.

Пример ввода
0 8
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
    int min, max;
    scanf("%i %i", &min, &max);

    while (min <= max)
    {
        ((min % 2) == 0) && printf("%i\n", min);
        min++;
    }
	return 0;
}
