#ifndef SIMPLE_C_LIBRARY_H
#define SIMPLE_C_LIBRARY_H

#define LSB 0
#define MSB 31

void setBit(unsigned int* pValue, unsigned int bit);

void clearBit(unsigned int* pValue, unsigned int bit);

void toggleBit(unsigned int* pValue, unsigned int bit);

int checkBit(const unsigned int* pValue, unsigned int bit);

#endif