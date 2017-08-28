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

int main()
{
    const int maxDigit = 9;
    const int convertDigitToLetter = 7;
    int input;
    int base;
    int maxFactor = 1;

    scanf("%d %u", &input, &base);

    if (input < 0)
    {
        input *= -1;
        printf("-");
    }

    for (int temp = input; temp >= base; temp /= base)
    {
        maxFactor *= base;
    }

    for (; maxFactor > 0; maxFactor /= base)
    {
        int offset = input / maxFactor;

        if (offset > maxDigit)
        {
            offset += convertDigitToLetter;
        }

        printf("%c", '0' + offset);

        input %= maxFactor;
    }
    printf("\n");

    return 0;
}