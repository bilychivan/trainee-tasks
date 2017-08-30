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

void arrayMerge(int target[], int src1[], int len1, int src2[], int len2)
{
    int summLen = len1 + len2;

    for (int i = 0, j = 0, k = 0; i < summLen; i++)
    {
        if (j < len1)
        {
            if (k < len2 && src2[k] < src1[j])
            {
                target[i] = src2[k];
                k += 1;
            }
            else
            {
                target[i] = src1[j];
                j += 1;
            }
        }
        else if (k < len2)
        {
            target[i] = src2[k];
            k += 1;
        }
    }
}

int main(void)
{
    int len1 = 7;
    int len2 = 9;
    int len3 = len1 + len2;
    int src1[7] = { 1, 3, 3, 4, 5, 8, 9 };
    int src2[9] = { 1, 2, 2, 3, 4, 6, 7, 8, 10 };
    int target[len3];

    arrayMerge(target, src1, len1, src2, len2);
    for ( int i = 0; i < len3; i++ ) {
        printf("%d ", target[i]);
    }
    printf("\n");
    
    return 0;
}