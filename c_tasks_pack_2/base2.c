/*
Задача base2

Условие задачи
Считать с клавиатуры целое число в десятичной системе счисления и основание
новой системы счисления (целое число от 2 до 36).
Вывести в консоль число, записанное в новой системе счисления.
В качестве цифр, превышающих 9, использовать заглавные буквы латинского
алфавита.
Для решения можно пользоваться только циклами. Задача решается без массивов.
Использовать только тип int.

Пример ввода
-255 16
Пример вывода
-FF

*/

#include <stdio.h>

#define ALPHA 'A'
#define DECMAX 9
#define MODULE 10

void integerToBase(int value, int base)
{
    int i = 1;
    int result;

    for (; value / i > base - 1; i *= base) {}

    for (; i != 0;)
    {
        result = value / i;
        if (result > DECMAX && result < base)
        {
            printf("%c", ALPHA + result % MODULE);
        }
        else
        {
            printf("%c", result + '0');
        }
        value %= i;
        i /= base;
    }
    printf("\n");
}

int main(void)
{
    int num;
    int base;

    scanf("%d %d", &num, &base);

    if (num < 0)
    {
        printf("-");
        num *= -1;
    }
    integerToBase(num, base);

    return 0;
}