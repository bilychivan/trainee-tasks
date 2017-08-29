#include "mylib.h"

int abs(int n)
{
    if (n < 0)
    {
        return n * -1;
    }

    return n;
}

void sliceReverse(int array[], int lo, int hi)
{
    int swap;

    for (; lo < hi; lo++, hi--)
    {
        swap = array[hi];
        array[hi] = array[lo];
        array[lo] = swap;
    }
}

char toLower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c += 32;
    }
    return c;
}