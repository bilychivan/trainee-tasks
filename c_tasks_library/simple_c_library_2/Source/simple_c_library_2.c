#include <stdio.h>
#include <simple_c_library_2.h>

unsigned int readNumber()
{
    unsigned int num;

    scanf("%u", &num);

    return num;
}

void displayNumber(unsigned int value)
{
    printf("%u", value);
}