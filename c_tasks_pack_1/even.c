/*
Задача even

Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все чётные числа от нуля до указанного числа включительно.

Пример ввода
7
Пример вывода
0 2 4 6

*/

#include <stdio.h>

int main()
{
    unsigned int max;
    scanf("%u", &max);

    printf("0 ");
    for (unsigned int i = 2; i < max; i += 2)
    {
        printf("%u ", i);
    }

    if ((max % 2) == 0)
    {
        printf("%u\n", max);
    }
    else
    {
        printf("\n");
    }
	return 0;
}
