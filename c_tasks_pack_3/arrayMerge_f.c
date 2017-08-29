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

// 1 2 3 4 5
// 2 3 5 9

#include <stdio.h>

void arrayMerge(int target[], int src1[], int len1, int src2[], int len2)
{
    int *src1_iterator = &src1[0];
    int *src2_iterator = &src2[0];
    int *src1_boundary = &src1[len1];
    int *src2_boundary = &src2[len2];
    int *target_iterator = &target[0];

    for (; (src1_iterator < src1_boundary) && (src2_iterator < src2_boundary);)
    {
        if (*src1_iterator <= *src2_iterator)
        {
            *target_iterator = *src1_iterator;
            target_iterator++;
            src1_iterator++;
        }
        else
        {
            *target_iterator = *src2_iterator;
            target_iterator++;
            src2_iterator++;
        }
    }

    if ((src1_iterator < src1_boundary) && (src2_iterator >= src2_boundary))
    {
        for (; src1_iterator < src1_boundary; *target_iterator++ = *src1_iterator++);
    }
    else
    {
        for (; src2_iterator < src2_boundary; *target_iterator++ = *src2_iterator++);
    }
}