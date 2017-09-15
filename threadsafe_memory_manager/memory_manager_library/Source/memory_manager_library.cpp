#include "memory_manager_library.h"

#include <unistd.h>
#include <cstring>
#include <mutex>

#define NALLOC 1024

struct alignas(16) Header
{
    Header* next;
    unsigned int size;
};

std::mutex mut;

static Header base;
static Header* freep = nullptr;
static Header* initPtr = nullptr;
bool flag = false;

static void freeMemory(void* ptr)
{
    Header* current = freep;
    Header* basePointer = (Header *)ptr - 1;

    for ( ; !(basePointer > current && basePointer < current->next); current = current->next)
    {
        if (current >= current->next && (basePointer > current || basePointer < current->next))
        {
            break;
        }
    }

    if (basePointer + basePointer->size == current->next)
    {
        basePointer->size += current->next->size;
        basePointer->next = current->next->next;
    }
    else
    {
        basePointer->next = current->next;
    }

    if (current + current->size == basePointer)
    {
        current->size += basePointer->size;
        current->next = basePointer->next;
    }
    else
    {
        current->next = basePointer;
    }

    freep = current;
}

static Header* morecore(unsigned unitNumber)
{
    Header* freeMemoryPtr = (Header *) sbrk(0);

    if (unitNumber < NALLOC)
    {
        unitNumber = NALLOC;
    }

    if (sbrk(unitNumber * sizeof(Header)) == (void *) -1)
    {
        return nullptr;
    }

    freeMemoryPtr->size = unitNumber;
    initPtr = freeMemoryPtr;

    freeMemory(freeMemoryPtr + 1);

    return freep;
}

static void* requestMemory(unsigned bytesNumber)
{
    Header* current, * prev;
    unsigned numberOfUnits = (bytesNumber + sizeof(Header) - 1) / sizeof(Header) + 1;

    prev = freep;

    if (prev == nullptr)
    {
        base.next = freep = prev = &base;
        base.size = 0u;
    }

    for (current = prev->next; ; prev = current, current = current->next)
    {
        if (current->size >= numberOfUnits)
        {
            if (current->size == numberOfUnits)
            {
                prev->next = current->next;
            }
            else
            {
                current->size -= numberOfUnits;
                current += current->size;
                current->size = numberOfUnits;
            }

            freep = prev;

            return (void *)(current + 1);
        }

        if (current == freep && (flag || (current = morecore(numberOfUnits)) == nullptr))
        {
            return nullptr;
        }
    }
}

void init(unsigned bytesNumber)
{
    std::lock_guard<std::mutex> lock(mut);

    requestMemory(bytesNumber);

    flag = true;
}

void freeAllMemory()
{
    std::lock_guard<std::mutex> lock(mut);

    brk(initPtr);
}

static void* changeMemorySize(void* oldPtr, unsigned bytesNumber)
{
    void* freeMemoryPtr = requestMemory(bytesNumber);

    if (freeMemoryPtr == nullptr)
    {
        return nullptr;
    }

    unsigned int unitNumber = (bytesNumber + sizeof(Header) - 1) / sizeof(Header) + 1;

    memcpy(freeMemoryPtr, oldPtr, unitNumber);

    freeMemory(oldPtr);

    return freeMemoryPtr;
}

void* changeMemorySizeSafe(void* ptr, unsigned bytesNumber)
{
    std::lock_guard<std::mutex> lock(mut);

    return changeMemorySize(ptr, bytesNumber);
}

void* requestMemorySafe(unsigned bytesNumber)
{
    std::lock_guard<std::mutex> lock(mut);

    return requestMemory(bytesNumber);
}

void freeMemorySafe(void* ptr)
{
    std::lock_guard<std::mutex> lock(mut);

    freeMemory(ptr);
}