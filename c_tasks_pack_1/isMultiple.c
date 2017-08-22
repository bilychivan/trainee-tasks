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
    int number, divisor;
    scanf("%d %d", &number, &divisor);

    if ((number % divisor) == 0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }

    return 0;
}
