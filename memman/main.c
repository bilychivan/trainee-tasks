#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "memman.h"

#define NUM_THREADS 1000

void test_sanity_1()
{
    int* x = (int*)mm_alloc(sizeof(int));
    *x = 777;

    if (*x != 777)
    {
        printf("SANITY FAILED\n");
        exit(1);
    }

    mm_free(x);
}

void* mm_test()
{
    test_sanity_1();
    test_sanity_1();
    test_sanity_1();
    test_sanity_1();
    test_sanity_1();

    void* bigchunk = mm_alloc(25);
    if (bigchunk == 0)
    {
        printf("alloc failed 1\n");
    }

    int* test_value = (int*)bigchunk;
    *test_value = 777;

    bigchunk = mm_realloc(bigchunk, 100);
    if (bigchunk == 0)
    {
        printf("realloc failed 1\n");
    }

    if (*test_value != 777)
    {
        printf("MEMORY CORRUPTED!\n");
    }

    void* bigchunk2 = mm_alloc(75);
    if (bigchunk2 == 0)
    {
        printf("realloc failed 2\n");
    }

    test_value = (int*)bigchunk2;
    *test_value = 777;

    bigchunk = mm_realloc(bigchunk, 150);
    if (bigchunk == 0)
    {
        printf("realloc failed 1.2\n");
    }

    bigchunk2 = mm_realloc(bigchunk2, 125);
    if (bigchunk2 == 0)
    {
        printf("realloc failed 2.2\n");
    }

    if (*test_value != 777)
    {
        printf("MEMORY CORRUPTED!\n");
    }

    mm_free(bigchunk);
    mm_free(bigchunk2);

    void* smallerchunk = mm_alloc(100);
    if (smallerchunk == 0)
    {
        printf("alloc failed 2\n");
    }

    mm_free(smallerchunk);

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread[NUM_THREADS];

    if (mm_start(65536) == MM_OK)
    {
        printf("Memory Manager initialized\n");
    }

    for (int i = 0, error_code; i < NUM_THREADS; i++)
    {
        if ((error_code = pthread_create(&thread[i], NULL, mm_test, NULL)))
        {
            printf("pthread_create failed, error code: %d\n", error_code);

            return 0;
        }
    }

    printf("Threads created, waiting for joining...\n");

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(thread[i], NULL);
    }

    printf("FINAL NODES:\n");
    mm_debug_nodes();

    mm_shutdown();

    return 0;
}