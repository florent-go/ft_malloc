// https://medium.com/a-42-journey/how-to-create-your-own-malloc-library-b86fedd39b96
#include "../include/malloc.h"

page_memory_t *g_page_memory = NULL;

void *start_malloc(size_t size)
{
    page_memory_t *heap;
    block_memory_t *block;
    void *res;

    if (!size)
        return (NULL);
    if ((block = try_fill_block(size)))
        return (BLOCK_SHIFT(block));
    if (!(heap = get_heap_of_block((const size_t)size)))
        return (NULL);
    res = Add_Empty_Block(heap, size);
    return res;
}

void *malloc(size_t size)
{
    void *res;
    if ((res = start_malloc(size)))
        ft_memset(res, 0xaa, size);
    return res;
}