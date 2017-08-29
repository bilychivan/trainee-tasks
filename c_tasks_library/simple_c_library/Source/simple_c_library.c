#include <simple_c_library.h>

void setBit(unsigned int* pValue, unsigned int bit)
{
    if (bit > MSB)
    {
        return;
    }

    *pValue |= (1u << bit);
}

void clearBit(unsigned int* pValue, unsigned int bit)
{
    if (bit > MSB)
    {
        return;
    }

    *pValue &= ~(1u << bit);
}

void toggleBit(unsigned int* pValue, unsigned int bit)
{
    if (bit > MSB)
    {
        return;
    }

    *pValue ^= (1u << bit);
}

int checkBit(const unsigned int* pValue, unsigned int bit)
{
    if (bit > MSB)
    {
        return 0;
    }

    return *pValue & (1u << bit);
}