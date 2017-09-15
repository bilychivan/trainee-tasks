#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MEMORY_HEADER "memory_manager_library.h"
#define MEMORY_START init
#define MEMORY_STOP freeAllMemory
#define MEMORY_ALLOC requestMemorySafe
#define MEMORY_REALLOC changeMemorySizeSafe
#define MEMORY_FREE freeMemorySafe

#include MEMORY_HEADER

#define NUM_THREADS 20
#define MIN_REQUESTS 1000
#define MIN_CHANK 16
#define VARIABLE_CHANK 16
#define GLOBAL_MEMORY_ALLOCATION 1024
#define MIN_SLEEP_MS 200
#define WAIT_SLEEP_MS 10
#define VARIABLE_SLEEP_MS 1900
#define EXIT_PROBABILITY 5

pthread_mutex_t lock;

void fill(char* data, int size, char character) {
    for (int i = 0; i < size; i++) {
        data[i] = character;
    }
}

void print(char* data, int size, int parameter, int number, int iteration) {
    int length = size - 1;

    pthread_mutex_lock(&lock);

    if (!parameter) {
        printf("th: %02d it: %03d >>> ", number, iteration);
    } else {
        printf("th: %02d it: %03d <<< ", number, iteration);
    }

    for (int i = 0; i < length; i++) {
        printf("%02d ", data[i]);
    }
    printf("%02d\n", data[length]);

    pthread_mutex_unlock(&lock);
}

void memory_test(int number, int iteration) {
    int size = MIN_CHANK + sizeof(char) * rand() % VARIABLE_CHANK + 1;
    int old_size = size;
    void* chunk;

    for (; !(chunk = MEMORY_ALLOC(size)); ) {
        pthread_mutex_lock(&lock);

        printf("th: %02d alloc wait\n", number);

        pthread_mutex_unlock(&lock);

        usleep(WAIT_SLEEP_MS);
    };

    fill((char*)chunk, size, (char) number);

    print((char*)chunk, size, 0, number, iteration);

    usleep(MIN_SLEEP_MS + rand() % VARIABLE_SLEEP_MS);

    size = MIN_CHANK + sizeof(char) * rand() % VARIABLE_CHANK + 1;
    for (void* old_chunk = chunk; !(chunk = MEMORY_REALLOC(old_chunk, size)); ) {
        pthread_mutex_lock(&lock);

        printf("th: %02d realloc wait\n", number);

        pthread_mutex_unlock(&lock);

        usleep(WAIT_SLEEP_MS);
    }

    if (old_size < size) {
        pthread_mutex_lock(&lock);

        printf("th: %02d refill\n", number);

        pthread_mutex_unlock(&lock);

        fill((char*)chunk, size, (char) number);
    }

    print((char*)chunk, size, 1, number, iteration);

    MEMORY_FREE(chunk);
}

void* test(void* number) {
    int i = 0;
    int thread_number = *((int*) number);

    for (; i < MIN_REQUESTS; i++) {
        memory_test(thread_number, i);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t thread[NUM_THREADS];

    printf(">>> START <<<\n");

    srand(time(0));

    MEMORY_START(GLOBAL_MEMORY_ALLOCATION);

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&thread[i], NULL, test, &i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread[i], NULL);
    }

    MEMORY_STOP();

    printf(">>> DONE <<<\n");

    return 0;
}
