#include <stdio.h>
#include "simple_c_library.h"
#include "simple_c_library_2.h"

void testSettingBit()
{
    unsigned int num = 0u;
    unsigned int bit = readNumber();

    printf("%s", "Before: ");
    displayNumber(num);
    printf("\n");

    setBit(&num, bit);

    printf("After: ");
    displayNumber(num);
    printf("\n----------\n");
}

void testClearingBit()
{
    unsigned int num = ~0u;
    unsigned int bit = readNumber();

    printf("%s", "Before: ");
    displayNumber(num);
    printf("\n");

    clearBit(&num, bit);

    printf("After: ");
    displayNumber(num);
    printf("\n----------\n");
}

void testTogglingBit()
{
    unsigned int num = readNumber();

    printf("%s", "Before: ");
    displayNumber(num);
    printf("\n");

    for (unsigned int i = LSB; i <= MSB; ++i)
    {
        toggleBit(&num, i);
    }

    printf("After: ");
    displayNumber(num);
    printf("\n----------\n");
}

void testCheckingBit()
{
    unsigned int num = readNumber();
    unsigned int bit = readNumber();

    if (checkBit(&num, bit))
    {
        printf("%u bit is enabled\n", bit);
    }
    else
    {
        printf("%u bit is disabled\n", bit);
    }
}

void test()
{
    printf("%s\n", "__testSettingBit__");
    testSettingBit();

    printf("%s\n", "__testClearingBit_");
    testClearingBit();

    printf("%s\n", "__testTogglingBit__");
    testTogglingBit();

    printf("%s\n", "__testCheckingBit__");
    testCheckingBit();
}

int main()
{
    test();

    return 0;
}