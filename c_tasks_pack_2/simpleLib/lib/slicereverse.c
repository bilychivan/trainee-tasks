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