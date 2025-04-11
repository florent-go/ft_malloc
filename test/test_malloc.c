#include "../includes/malloc.h"

void test_malloc_null()
{
    void *t = malloc(0);
    if (t)
        printf("malloc(0) should return NULL\n");
    show_alloc_mem();
    free(t);
    show_alloc_mem();
}

void test_malloc_getpagesize()
{
    void *t = malloc(getpagesize());
    show_alloc_mem();
    free(t);
    show_alloc_mem();
}

void test_malloc_one()
{
    char *t = (char *)malloc(1);
    if (!t) {
        printf("malloc(1) should return ptr\n");
        return;
    }
    t[0] = 0xFF;
    t[1] = 0xFF;
    t[2] = 0xFF;
    t[3] = 0xFF;

    t[0] = 0;
    show_alloc_mem();
    free(t);
    show_alloc_mem();
}