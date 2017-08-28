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

int main()
{
    const int ROTATE_NUMBER = 13;
    const int ALPHABET_SIZE = 26;
    FILE* inputFile;
    FILE* outputFile;
    unsigned int inputLength;

    inputFile = fopen("rot13.in", "r");

    fseek(inputFile, 0, SEEK_END);
    inputLength = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    if (inputLength > 100)
    {
        inputLength = 100;
    }

    unsigned char inputChars[inputLength];
    fread(&inputChars, inputLength, 1, inputFile);

    for (unsigned int i = 0; i < inputLength; i++)
    {
        if ((inputChars[i] >= 'A') && (inputChars[i] <= 'Z'))
        {
            inputChars[i] += ROTATE_NUMBER;
            if (inputChars[i] > 'Z')
            {
                inputChars[i] -= ALPHABET_SIZE;
            }
        }
        else
        {
            inputChars[i] += ROTATE_NUMBER;
            if (inputChars[i] > 'z')
            {
                inputChars[i] -= ALPHABET_SIZE;
            }
        }
    }

    fclose(inputFile);


    outputFile = fopen("rot13.out", "w");

    fwrite(&inputChars, inputLength, 1, inputFile);

    fclose(outputFile);

    return 0;
}