/*
Задача maxN

Условие задачи
Считать с клавиатуры целое положительное число - количество чисел в
последовательности.
Затем считать с клавиатуры заданное количество чисел и вывести наибольшее из
них.
Данная задача решается без массивов.

Пример ввода
5
1 2 3 4 5
Пример вывода
5

*/

#include <stdio.h>

int main()
{
    int numberOfInputs, max;
    scanf("%d %d", &numberOfInputs, &max);

    while (numberOfInputs > 1)
    {
        int temp;
        scanf("%d", &temp);

        if (max < temp)
        {
            max = temp;
        }
        numberOfInputs--;
    }

    printf("%i\n", max);
    return 0;
}
