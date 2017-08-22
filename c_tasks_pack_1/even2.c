/*
Задача even2

Условие задачи
Считать с клавиатуры два целых числа.
Вывести в строку все чётные числа в промежутке от первого до второго
включительно.
В указанном промежутке гарантировано наличие хотя бы одного числа, подлежащего
выводу.

Пример ввода
7 15
Пример вывода
8 10 12 14

*/

#include <stdio.h>

int main()
{
    unsigned int min, max;
    scanf("%u %u", &min, &max);

    while (min <= max)
    {
        ((min % 2) == 0) && printf("%u ", min);
        min++;
    }
	return 0;
}
