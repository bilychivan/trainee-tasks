/*
Задача minN

Условие задачи
Считать с клавиатуры целое положительное число - количество чисел в
последовательности.
Затем считать с клавиатуры заданное количество чисел и вывести наименьшее из
них.
Данная задача решается без массивов.

Пример ввода
5
1 2 3 4 5
Пример вывода
1

*/

#include <stdio.h>

int main()
{
    int numberOfInputs, min;
    scanf("%d %d", &numberOfInputs, &min);

    while (numberOfInputs > 1)
    {
        int temp;
        scanf("%d", &temp);

        if (min > temp)
        {
            min = temp;
        }
        numberOfInputs--;
    }

    printf("%i\n", min);
    return 0;
}
