/*
Задача rot13

Условие задачи
Считать из файла task.in в память строку длиной не более 100 символов.
Зашифровать её по алгоритму ROT13.
Результат вывести в task.out.

Пример ввода
balk
Пример вывода
onyx

*/

#include <stdio.h>

#define OFFSET 13

void rot13(FILE* ptrFile, char* pStr)
{
    for ( ; *pStr; pStr++)
    {
        if ((*pStr >= 'a' && *pStr <= 'm') || (*pStr >= 'A' && *pStr <= 'M'))
        {
            *pStr += OFFSET;
        }
        else if ((*pStr >= 'n' && *pStr <= 'z') || (*pStr >= 'n' && *pStr <= 'z'))
        {
            *pStr -= OFFSET;
        }

        fprintf(ptrFile, "%c", *pStr);
    }
    fprintf(ptrFile, "\n");
}

int main()
{
    FILE* pInputFile = fopen("task.in", "r");
    FILE* pOutputFile = fopen("task.out", "w");
    const unsigned int size = 101;
    char str[size];

    fscanf(pInputFile, "%100s", str);

    rot13(pOutputFile, str);

    fclose(pInputFile);
    fclose(pOutputFile);

    return 0;
}