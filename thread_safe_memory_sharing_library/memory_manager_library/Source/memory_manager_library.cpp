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

static void freeMemory(void* ap)
{
    Header* p = freep;
    Header* bp = (Header *)ap - 1;

    for ( ; !(bp > p && bp < p->s.next); p = p->s.next)
    {
        if (p >= p->s.next && (bp > p || bp < p->s.next))
        {
            break;
        }
    }

    if (bp + bp->s.size == p->s.next)
    {
        bp->s.size += p->s.next->s.size;
        bp->s.next = p->s.next->s.next;
    }
    else
    {
        bp->s.next = p->s.next;
    }

    if (p + p->s.size == bp)
    {
        p->s.size += bp->s.size;
        p->s.next = bp->s.next;
    }
    else
    {
        p->s.next = bp;
    }

    freep = p;
}

static Header* morecore(unsigned nu)
{
    Header* cp = (Header *) sbrk(0);

    if (nu < NALLOC)
    {
        nu = NALLOC;
    }

    if (sbrk(nu * sizeof(Header)) == (void *) -1)
    {
        return nullptr;
    }

    cp->s.size = nu;
    initPtr = cp;

    freeMemory(cp + 1);

    return freep;
}

static void* requestMemory(unsigned nbytes)
{
    Header* p, * prevp;
    unsigned nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    if ((prevp = freep) == nullptr)
    {
        base.s.next = freep = prevp = &base;
        base.s.size = 0;
    }

    for (p = prevp->s.next; ; prevp = p, p = p->s.next)
    {
        if (p->s.size >= nunits)
        {
            if (p->s.size == nunits)
            {
                prevp->s.next = p->s.next;
            }
            else
            {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }

            freep = prevp;

            return (void *)(p + 1);
        }

        if (p == freep)
        {
            if (flag || (p = morecore(nunits)) == nullptr)
            {
                return nullptr;
            }
        }
    }
}

void init(unsigned nbytes)
{
    std::lock_guard<std::mutex> lock(mut);

    requestMemory(nbytes);

    flag = true;
}

void freeAllMemory()
{
    std::lock_guard<std::mutex> lock(mut);

    brk(initPtr);
}

static void* changeMemorySize(void* ap, unsigned nbytes)
{
    void* p = requestMemory(nbytes);

    if (p == nullptr)
    {
        return nullptr;
    }

    unsigned int nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;

    memcpy(p, ap, nunits);

    freeMemory(ap);

    return p;
}

void* changeMemorySizeSafe(void* ap, unsigned nbytes)
{
    std::lock_guard<std::mutex> lock(mut);

    return changeMemorySize(ap, nbytes);
}

void* requestMemorySafe(unsigned nbytes)
{
    std::lock_guard<std::mutex> lock(mut);

    return requestMemory(nbytes);
}

void freeMemorySafe(void *ap)
{
    std::lock_guard<std::mutex> lock(mut);

    freeMemory(ap);
}