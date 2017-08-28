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

#define INITIAL_BASE_SYSTEM 10
#define VAL_TO_CHAR_OFFSET 7    //'A' - '0' - INITIAL_BASE_SYSTEM

int main()
{
    int num, new_base;
    int prevPower, powerOfBase = 1;

    scanf("%d %d", &num, &new_base);

    if (num < 0)
    {
       num = -num;

       printf("-");
    }

    prevPower = num / new_base;
    for ( ; powerOfBase < prevPower; powerOfBase *= new_base)
    {
        //empty loop body
    }

    for ( ; powerOfBase ; powerOfBase /= new_base)
    {
       int remainder = num / powerOfBase;

       if (remainder >= INITIAL_BASE_SYSTEM)
       {
           remainder += VAL_TO_CHAR_OFFSET;
       }

       printf("%c", remainder + '0');    //int to char conversion

       num %= powerOfBase;
    }
    printf("\n");

    return 0;
}