/*
Задача multiple5
Условие задачи
Считать с клавиатуры целое положительное число.
Вывести в строку все числа, кратные 5, от нуля до указанного числа включительно.

Пример ввода
17
Пример вывода
0 5 10 15

*/

#include <stdio.h>

int main()
{
    unsigned int max;
    scanf("%u", &max);

    for (unsigned int i = 0; i < max; i += 5)
    {
        printf("%u ", i);
    }

    if ((max % 5) == 0)
    {
        printf("%u\n", max);
    }
    else
    {
        printf("\n");
    }
	return 0;
}
