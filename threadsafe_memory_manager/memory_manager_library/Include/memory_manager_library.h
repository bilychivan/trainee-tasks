#ifndef MEMORY_MANAGER_LIBRARY_H
#define MEMORY_MANAGER_LIBRARY_H

void init(unsigned bytesNumber);

void freeAllMemory();

void* changeMemorySizeSafe(void* oldPtr, unsigned bytesNumber);

void* requestMemorySafe(unsigned bytesNumber);

void freeMemorySafe(void* ptr);

#endif