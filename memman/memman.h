#ifndef MEMMAN_H
#define MEMMAN_H

#include <stdint.h>

#define MM_OK   0
#define MM_FAIL 1

typedef int64_t mm_size;

int mm_start(mm_size size);
void* mm_alloc(mm_size size);
void* mm_realloc(void* ptr, mm_size new_size);
void mm_free(void* ptr);
void mm_debug_nodes();
void mm_shutdown();

#endif // MEMMAN_H
