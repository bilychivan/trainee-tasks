/*
Задача arrayMerge()

Условие задачи
Написать функцию
void arrayMerge(int target[], int src1[], int len1, int src2[], int len2)

Массивы src1[] и src2[] (длиной len1 и len2 соответственно) отсортированы по
неубыванию.
Произвести слияние этих массивов в массив target[], также отсортированный по
неубыванию.
В случае равенства предпочтение отдаётся элементам из первого массива.
Требуемая сложность: O(N)

*/

#include <stdio.h>

#define FIRST_SIZE 10
#define SECOND_SIZE 5
#define RESULT_SIZE 15

void arrayMerge(int target[], const int src1[], int len1, const int src2[], int len2)
{
    for (int k = 0, i = 0, j = 0, size = len1 + len2; k < size; ++k)
    {
        if (i >= len1 || (j < len2 && src2[j] < src1[i]))
        {
            target[k] = src2[j++];
        }
        else
        {
            target[k] = src1[i++];
        }
    }
}

void display(const int array[], int len)
{
    if (len < 1)
    {
        printf("\n");

        return;
    }

    int size = len - 1;

    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[size]);
}

void test(int target[], const int src1[], int len1, const int src2[], int len2)
{
    display(src1, len1);
    display(src2, len2);

    arrayMerge(target, src1, len1, src2, len2);

    display(target, len1 + len2);

    printf("--------------------\n");
}

int main()
{
    const int firstArray[] =
    {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    };
    const int secondArray[] =
    {
        10, 11, 12, 13, 14
    };
    int resultArray[RESULT_SIZE];

    test(resultArray, firstArray, FIRST_SIZE, secondArray, SECOND_SIZE);
    test(resultArray, secondArray, SECOND_SIZE, firstArray, FIRST_SIZE);
    test(resultArray, firstArray, 0, secondArray, 3);
    test(resultArray, firstArray, 4, secondArray, 2);
    test(resultArray, firstArray, 2, firstArray, 2);

    return 0;
}