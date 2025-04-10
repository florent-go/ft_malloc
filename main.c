#include "./include/malloc.h"

int main()
{
    printf("======================= TINY Addr ========================\n");
    void *tiny_min2;
    tiny_min2 = malloc(14);
    void *tiny_min;
    tiny_min = malloc(13);
    void *tiny_max;
    tiny_max = malloc(12);
    void *tiny;
    tiny = malloc(512);
    show_alloc_mem();
    return 0;
}