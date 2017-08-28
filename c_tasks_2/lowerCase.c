/*
Задача lowerCase

Условие задачи
В файле task.in дана последовательность символов.
Перевести все буквы в нижний регистр и вывести результирующую последовательность
в файл task.out

Пример ввода
ABCD
Пример вывода
abcd

*/

#include <stdio.h>

#define OFFSET 32       //'A' - 'a' = 97 - 65 = 32
    
int main()
{
    FILE* pInputFile = fopen("task.in", "r");
    FILE * pOutputFile = fopen("task.out", "w");

    for (char symbol; fscanf(pInputFile, "%c", &symbol) != EOF ; )
    {
        if (symbol >= 'A' && symbol <= 'Z')
        {
            symbol += OFFSET;
        }

        fprintf(pOutputFile, "%c", symbol);
    }
    fprintf(pOutputFile, "\n");

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}