#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <pthread.h>

#include "memman.h"

#define TRUE 1
#define FALSE 0

#define DEFAULT_STREAM stdout
#define MM_DEBUG

static void* mm_memory = 0;
static mm_size mm_budget = 0;
pthread_mutex_t mm_node_lock;

typedef struct mm_node
{
    int unoccupied;
    mm_size length;
    #ifdef MM_DEBUG
        mm_size debug_offset;
    #endif
    struct mm_node* next;
} mm_node;

typedef struct mm_node_meta
{
    mm_node* owner_node;
} mm_node_meta;

static mm_node* mm_memory_root;

static void mm_error(const char* format, ... )
{
    va_list arglist;

    fprintf(DEFAULT_STREAM, "MM error: ");

    va_start(arglist, format);

    vfprintf(DEFAULT_STREAM, format, arglist);

    va_end(arglist);
}

static void mm_warning(const char* format, ... )
{
    va_list arglist;

    fprintf(DEFAULT_STREAM, "MM warning: ");

    va_start(arglist, format);

    vfprintf(DEFAULT_STREAM, format, arglist);

    va_end(arglist);
}

static void* mm_allocate_node()
{
    void* tmp = malloc(sizeof(mm_node));

    if (tmp == 0)
    {
        mm_error("failed to allocate %d bytes (out of OS memory)\n", sizeof(mm_node));
        exit(1);
    }

    return tmp;
}

static void mm_defragment(mm_node* target)
{
    pthread_mutex_lock(&mm_node_lock);

    for (mm_node* tmp = target; tmp != 0; tmp = tmp->next)
    {
        if (tmp->next != 0)
        {
            if ((tmp->unoccupied == TRUE) && (tmp->next->unoccupied == TRUE))
            {
                tmp->length += tmp->next->length;

                mm_node* del = tmp->next;

                tmp->next = tmp->next->next;

                free(del);

                mm_defragment(tmp);
            }
        }
    }

    pthread_mutex_unlock(&mm_node_lock);
}

void* mm_alloc(mm_size size)
{
    pthread_mutex_lock(&mm_node_lock);

    mm_size mem_offset = 0;

    for (mm_node* tmp = mm_memory_root; tmp != 0; tmp = tmp->next)
    {
        if (tmp->unoccupied == TRUE)
        {
            mm_size required_size = size + sizeof(mm_node_meta);

            if (tmp->length >= required_size)
            {
                if (tmp->next == 0)
                {
                    mm_node* new_node = mm_allocate_node();

                    new_node->unoccupied = TRUE;
                    new_node->length = tmp->length - size - sizeof(mm_node_meta);
                    new_node->next = 0;
                    #ifdef MM_DEBUG
                        new_node->debug_offset = tmp->debug_offset + size + sizeof(mm_node_meta);
                    #endif

                    tmp->unoccupied = FALSE;
                    tmp->length = required_size;
                    tmp->next = new_node;

                    mm_node_meta* node_meta = (mm_node_meta*)(mm_memory + mem_offset);
                    node_meta->owner_node = tmp;

                    pthread_mutex_unlock(&mm_node_lock);
                    return (mm_memory + mem_offset + sizeof(mm_node_meta));
                }
                else
                {
                    tmp->unoccupied = FALSE;

                    if (tmp->length > required_size)
                    {
                        mm_node* new_node = mm_allocate_node();

                        new_node->unoccupied = TRUE;
                        new_node->length = tmp->length - size - sizeof(mm_node_meta);
                        new_node->next = tmp->next;
                        #ifdef MM_DEBUG
                            new_node->debug_offset = tmp->debug_offset + size + sizeof(mm_node_meta);
                        #endif

                        tmp->next = new_node;
                        tmp->length = required_size;
                    }

                    mm_node_meta* node_meta = (mm_node_meta*)(mm_memory + mem_offset);
                    node_meta->owner_node = tmp;

                    pthread_mutex_unlock(&mm_node_lock);
                    return (mm_memory + mem_offset + sizeof(mm_node_meta));
                }
            }
        }

        mem_offset += tmp->length;
    }

    pthread_mutex_unlock(&mm_node_lock);
    return 0;
}

void mm_free(void* ptr)
{
    if (ptr == 0)
    {
        return;
    }

    pthread_mutex_lock(&mm_node_lock);

    mm_node_meta* node_meta = (mm_node_meta*)(ptr - sizeof(mm_node_meta));

    if (node_meta->owner_node->unoccupied == FALSE)
    {
        node_meta->owner_node->unoccupied = TRUE;
        mm_defragment(mm_memory_root);
    }
    else
    {
        mm_warning("double free detected\n");
    }

    pthread_mutex_unlock(&mm_node_lock);
}

void* mm_realloc(void* ptr, mm_size new_size)
{
    if (ptr == 0)
    {
        if (new_size > 0)
        {
            return mm_alloc(new_size);
        }
        else
        {
            return 0;
        }
    }

    if (new_size == 0)
    {
        mm_free(ptr);

        return 0;
    }

    pthread_mutex_lock(&mm_node_lock);

    mm_node_meta* node_meta = (mm_node_meta*)(ptr - sizeof(mm_node_meta));

    if (node_meta->owner_node->unoccupied == FALSE)
    {
        if (node_meta->owner_node->length == new_size)
        {
            pthread_mutex_unlock(&mm_node_lock);
            return ptr;
        }

        if (node_meta->owner_node->length > new_size)
        {
            mm_node* new_node = mm_allocate_node();

            new_node->unoccupied = TRUE;
            new_node->length = node_meta->owner_node->length - new_size;
            new_node->next = (node_meta->owner_node->next != 0) ? node_meta->owner_node->next : 0;
            #ifdef MM_DEBUG
                new_node->debug_offset = node_meta->owner_node->debug_offset + new_size + sizeof(mm_node_meta);
            #endif

            node_meta->owner_node->next = new_node;
            node_meta->owner_node->length = new_size;

            mm_defragment(new_node);

            pthread_mutex_unlock(&mm_node_lock);
            return ptr;
        }
        else
        {
            void* new_ptr = mm_alloc(new_size);
            if (new_ptr == 0)
            {
                pthread_mutex_unlock(&mm_node_lock);
                return 0;
            }

            memcpy(new_ptr, ptr, node_meta->owner_node->length);

            mm_free(ptr);

            pthread_mutex_unlock(&mm_node_lock);
            return new_ptr;
        }
    }
    else
    {
        mm_warning("realloc of freed memory detected\n");
    }

    pthread_mutex_unlock(&mm_node_lock);
    return 0;
}

void mm_debug_nodes()
{
    pthread_mutex_lock(&mm_node_lock);

    for (mm_node* tmp = mm_memory_root; tmp != 0; tmp = tmp->next)
    {
        #ifdef MM_DEBUG
            printf("Node (%lX) (%ld; %s; %ld; %lX)\n", (mm_size)tmp, tmp->debug_offset, (tmp->unoccupied == TRUE) ? "FREE" : "NOTF", tmp->length, (mm_size)tmp->next);
        #else
            printf("Node (%lX) (%s; %ld; %lX)\n", (mm_size)tmp, (tmp->unoccupied == TRUE) ? "FREE" : "NOTF", tmp->length, (mm_size)tmp->next);
        #endif
    }

    pthread_mutex_unlock(&mm_node_lock);
}

int mm_start(mm_size size)
{
    pthread_mutexattr_t lock_attr;

    if (size == 0)
    {
        mm_error("memory budget can't be zero\n");

        return MM_FAIL;
    }

    mm_memory = (void*) malloc(size);

    if (mm_memory == 0)
    {
        mm_error("failed to allocate memory from OS\n");

        return MM_FAIL;
    }

    if (pthread_mutexattr_init(&lock_attr) != 0)
    {
        mm_error("failed to init mutex attr\n");

        return MM_FAIL;
    }

    if (pthread_mutexattr_settype(&lock_attr, PTHREAD_MUTEX_RECURSIVE) != 0)
    {
        mm_error("failed to set mutex attr type\n");

        return MM_FAIL;
    }

    if (pthread_mutex_init(&mm_node_lock, &lock_attr) != 0)
    {
        mm_error("failed to acquire mutex from OS\n");

        return MM_FAIL;
    }

    mm_budget = size;

    mm_memory_root = mm_allocate_node();
    mm_memory_root->unoccupied = TRUE;
    mm_memory_root->length = mm_budget;
    mm_memory_root->next = 0;
    #ifdef MM_DEBUG
        mm_memory_root->debug_offset = 0;
    #endif

    return MM_OK;
}

void mm_shutdown()
{
    mm_node* tmp = mm_memory_root;
    mm_size total_size = 0;

    while (tmp != 0)
    {
        if (tmp->unoccupied == FALSE)
        {
            mm_warning("leak of %ld bytes detected\n", tmp->length);
        }

        total_size += tmp->length;

        mm_node* next = tmp->next;

        free(tmp);

        tmp = next;
    }

    if (total_size != mm_budget)
    {
        mm_error("%ld (memory budget) != %ld (memory size) | bug detected, pls fix me!\n", mm_budget, total_size);
    }
}