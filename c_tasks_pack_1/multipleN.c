/*
Задача multipleN

Условие задачи
Считать с клавиатуры целое неотрицательное число-максимум.
Считать с клавиатуры целый, не равный нулю делитель.
Вывести в строку числа от нуля до указанного максимума включительно, кратные
заданному делителю.

Пример ввода
99 10
Пример вывода
0 10 20 30 40 50 60 70 80 90

*/

#include <stdio.h>

int main()
{
    unsigned int max;
    int divisor;
    scanf("%u %i", &max, &divisor);

    for (unsigned int i = 0; i < max; i += divisor)
    {
        printf("%u ", i);
    }

    if ((max % divisor) == 0)
    {
        printf("%u\n", max);
    }
    else
    {
        printf("\n");
    }
	return 0;
}
