/*
Задача strReverse

Условие задачи
В файле task.in дана строка длиной не более 100 символов.
Прочитать строку в память и произвести ее реверс.
Результат вывести в task.out.

Пример ввода
hello
Пример вывода
olleh

*/

#include <stdio.h>

unsigned int strLength(const char* str)
{
    unsigned int length = 0u;
    for (; *str++; )
    {
        length += 1u;
    }

    return length;
}

void reverseString(char* str)
{
    for (char* end = str + strLength(str) - 1; str < end; str++, end--)
    {
        char temp = *str;
        *str = *end;
        *end = temp;
    }
}

int main()
{
    FILE* pInputFile = fopen("task.in", "r");
    FILE* pOutputFile = fopen("task.out", "w");
    const unsigned int QUANTITY = 101;
    char str[QUANTITY];

    fscanf(pInputFile, "%100s", str);

    reverseString(str);

    fprintf(pOutputFile, "%s\n", str);

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}