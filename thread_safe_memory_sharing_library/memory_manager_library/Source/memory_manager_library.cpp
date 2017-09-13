#include "memory_manager_library.h"

#include <unistd.h>
#include <cstring>
#include <mutex>

typedef long Align;

union header
{
    struct
    {
        union header* next;
        unsigned int size;
    } s;
    Align x;
};

typedef union header Header;

std::mutex mut;

static Header base;
static Header* freep = nullptr;
static Header* initPtr = nullptr;
bool flag = false;

#define NALLOC 1024

static void freeMemory(void*  ptr)
{
    Header* current = freep;
    Header* basePointer = (Header *)ptr - 1;

    for ( ; !(basePointer > current && basePointer < current->s.next); current = current->s.next)
    {
        if (current >= current->s.next && (basePointer > current || basePointer < current->s.next))
        {
            break;
        }
    }

    if (basePointer + basePointer->s.size == current->s.next)
    {
        basePointer->s.size += current->s.next->s.size;
        basePointer->s.next = current->s.next->s.next;
    }
    else
    {
        basePointer->s.next = current->s.next;
    }

    if (current + current->s.size == basePointer)
    {
        current->s.size += basePointer->s.size;
        current->s.next = basePointer->s.next;
    }
    else
    {
        current->s.next = basePointer;
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

    freeMemoryPtr->s.size = unitNumber;
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
        base.s.next = freep = prev = &base;
        base.s.size = 0u;
    }

    for (current = prev->s.next; ; prev = current, current = current->s.next)
    {
        if (current->s.size >= numberOfUnits)
        {
            if (current->s.size == numberOfUnits)
            {
                prev->s.next = current->s.next;
            }
            else
            {
                current->s.size -= numberOfUnits;
                current += current->s.size;
                current->s.size = numberOfUnits;
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

    unsigned int nunits = (bytesNumber + sizeof(Header) - 1) / sizeof(Header) + 1;

    memcpy(freeMemoryPtr, oldPtr, nunits);

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