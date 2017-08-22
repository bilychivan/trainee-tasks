/*
Задача isMultiple

Условие задачи
Считать с клавиатуры два целых числа, причем второе из них не равно нулю.
Если первое кратно второму, вывести на экран yes, иначе вывести no.

Пример ввода
25 5
Пример вывода
yes

*/

#include <stdio.h>

int main()
{
    int n, div;
    scanf("%i %i", &n, &div);

    if (div == 0)
    {
        puts("div can't be 0");
        return 0;
    }

    ((n % div) == 0) ? puts("yes") : puts("no");
	return 0;
}
