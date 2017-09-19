#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef struct s_block
{
    struct s_block *next;
    struct s_block *prev;
    int isFree;
    size_t size;
    void *memoryAddress;
} tBlock;

void initGlobalMemory(size_t size);
void *memoryAllocation(size_t size);
void freeMemBlock(void *address);
void *reallocMemBlock(void *address, size_t size);
void *reallocMemory(void *address, size_t size);
void freeMemory(void *address);
void *requestMemory(size_t size);
void freeGlobalMem();

#endif //MYMALLOC_H
