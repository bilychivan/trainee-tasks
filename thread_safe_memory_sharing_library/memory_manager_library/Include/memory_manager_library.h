#ifndef MEMORY_MANAGER_LIBRARY_H
#define MEMORY_MANAGER_LIBRARY_H

void init(unsigned nbytes);

void freeAllMemory();

void* changeMemorySizeSafe(void* ap, unsigned nbytes);

void* requestMemorySafe(unsigned nbytes);

void freeMemorySafe(void* ap);

#endif