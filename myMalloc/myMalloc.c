#include "myMalloc.h"

pthread_mutex_t lock2;

const int BLOCK_SIZE = sizeof(tBlock);
tBlock *head = NULL;

static tBlock *createNewBlock(size_t size, void *address);

void initGlobalMemory(size_t size)
{
    void *memoryInit;

    if (size < BLOCK_SIZE + 1)
    {
        return;
    }

    if (!head)
    {
        pthread_mutex_init(&lock2, NULL);
        if ((memoryInit = malloc(size)) == NULL)
        {
            return;
        }
        head = createNewBlock(size - BLOCK_SIZE, memoryInit);

        printf("Memory is allocated\n");
    }
}

static tBlock *createNewBlock(size_t size, void *address)
{
    tBlock *block = (tBlock *) address;

    block->next = NULL;
    block->prev = NULL;
    block->isFree = TRUE;
    block->size = size;
    block->memoryAddress = address + BLOCK_SIZE;

    return block;
}

static size_t sizeOfFirstFreeBlock(size_t size)
{
    for (tBlock *current = head; current != NULL; current = current->next)
    {
        if (current->isFree && current->size >= size)
        {
            return current->size;
        }
    }

    return 0;
}

static tBlock *searchSuitableMemoryBlock(size_t size)
{
    tBlock *res = NULL;
    size_t minSize = sizeOfFirstFreeBlock(size);

    for (tBlock *current = head; current != NULL; current = current->next)
    {
        if (current->isFree && current->size <= minSize && current->size >= size)
        {
            res = current;
            minSize = current->size;
        }
    }

    return res;
}

static void createLinkForNewBlock(tBlock *curr, tBlock *new)
{
    if (curr && new)
    {
        if (curr->next)
        {
            new->next = curr->next;
            curr->next->prev = new;
        }
        curr->next = new;
        new->prev = curr;
    }
}

void *memoryAllocation(size_t size)
{
    tBlock *res = NULL;
    tBlock *neighbor = NULL;
    size_t memRequest = size + BLOCK_SIZE;

    if (head && size != 0)
    {
        if ((res = searchSuitableMemoryBlock(memRequest)) == NULL)
        {
            printf("Not enough memory\n");
            sleep(1);

            return NULL;
        }
        if (res->size > memRequest + BLOCK_SIZE)
        {
            neighbor = createNewBlock(res->size - memRequest, (void *) res + memRequest);
            createLinkForNewBlock(res, neighbor);
            res->size = size;
        }
        res->isFree = FALSE;

        return res->memoryAddress;
    }

    return NULL;
}

static void deleteMemBlock(tBlock *current)
{
    if (current->next)
    {
        current->next->prev = current->prev;

    }
    if (current->prev)
    {
        current->prev->next = current->next;
    }
}

static void freeNeighborsBlocks(tBlock *current)
{
    tBlock *removableBlock;

    for (; current->prev || current->next;)
    {
        if (current->next && current->next->isFree)
        {
            current->size += current->next->size + BLOCK_SIZE;
            removableBlock = current->next;

            current->next = current->next->next;
            deleteMemBlock(removableBlock);
        }
        else if (current->prev && current->prev->isFree)
        {
            current->prev->size += current->size + BLOCK_SIZE;
            removableBlock = current;
            current = current->prev;
            deleteMemBlock(removableBlock);
        }
        else
        {
            break;
        }
    }
}


void freeMemBlock(void *address)
{
    tBlock *current = address - BLOCK_SIZE;

    if (current)
    {
        if (current->isFree)
        {
            printf("Double free\n");

            return;
        }
        current->isFree = TRUE;

        freeNeighborsBlocks(current);
    }
}

void *reallocMemBlock(void *address, size_t size)
{
    tBlock *current = address - BLOCK_SIZE;
    size_t sizeOfCopy = 0;
    tBlock *newBlock = NULL;
    void *newAddress;

    if (size == 0)
    {
        return NULL;
    }

    newAddress = memoryAllocation(size);
    if (newAddress != NULL)
    {
        newBlock = newAddress - BLOCK_SIZE;
        if (size < current->size)
        {
            sizeOfCopy = size;
        }
        else
        {
            sizeOfCopy = current->size;
        }

        memcpy(newBlock->memoryAddress, current->memoryAddress, sizeOfCopy);

        freeMemBlock(address);

        return newBlock->memoryAddress;
    }

    return NULL;
}

void *reallocMemory(void *address, size_t size)
{
    pthread_mutex_lock(&lock2);

    void *res = reallocMemBlock(address, size);

    pthread_mutex_unlock(&lock2);

    return res;
}

void freeMemory(void *address)
{
    pthread_mutex_lock(&lock2);

    freeMemBlock(address);

    pthread_mutex_unlock(&lock2);
}

void *requestMemory(size_t size)
{
    pthread_mutex_lock(&lock2);

    void *res = memoryAllocation(size);

    pthread_mutex_unlock(&lock2);

    return res;
}

void freeGlobalMem()
{
    if (head)
    {
        for (tBlock *current = head; current; current = current->next)
        {
            if (current->next && current->next->isFree)
            {
                freeMemBlock(current->next->memoryAddress);
            }
            if (!current->isFree)
            {
                printf("Leaks has been detected -> %p - size of = %zu bytes\n", current, current->size);
            }
        }

        printf("Memory has been freed\n");
    }
    else
    {
        printf("Memory not initialized\n");
    }
}