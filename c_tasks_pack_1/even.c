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
    unsigned int number;
    scanf("%u", &number);

    for (unsigned int i = 0; i <= number; i++)
    {
        ((i % 2) == 0) && printf("%u ", i);
    }
	return 0;
}
