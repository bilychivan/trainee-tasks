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
#define SIZE 101

void rot13(char* pStr)
{
    for ( ; *pStr; pStr++)
    {
        if ((*pStr >= 'a' && *pStr <= 'm') || (*pStr >= 'A' && *pStr <= 'M'))
        {
            *pStr += OFFSET;
        }
        else if ((*pStr >= 'n' && *pStr <= 'z') || (*pStr >= 'N' && *pStr <= 'Z'))
        {
            *pStr -= OFFSET;
        }
    }
}

void writeResultToOutputFile(const char* pStr)
{
    FILE* OutputFile = fopen("task.out", "w");

    fprintf(OutputFile, "%s\n", pStr);

    fclose(OutputFile);
}

int main()
{
    FILE* InputFile = fopen("task.in", "r");
    char str[SIZE];

    fscanf(InputFile, "%100s", str);

    fclose(InputFile);

    rot13(str);

    writeResultToOutputFile(str);

    return 0;
}