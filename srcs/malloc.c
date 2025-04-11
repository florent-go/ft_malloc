// https://medium.com/a-42-journey/how-to-create-your-own-malloc-library-b86fedd39b96
#include "../includes/malloc.h"

pthread_mutex_t     g_mutex = PTHREAD_MUTEX_INITIALIZER;
page_memory_t       *g_page_memory = NULL;

size_t  align_size(size_t size)
{
    return ((((size - 1) >> 4) << 4) + 16);
}

void *start_malloc(size_t size)
{
    page_memory_t   *page;
    block_memory_t  *block;
    void            *res;

    if (!size)
        return (NULL);
    size = align_size(size);

    if ((block = try_fill_block(size))) 
        return (block_shift(block));
    if (!(page = get_page_with_block_size((const size_t)size)))
        return (NULL);
    res = add_empty_block(page, size);
    return res;
}

void *malloc(size_t size)
{
    void *res;

    pthread_mutex_lock(&g_mutex);

    if ((res = start_malloc(size)))
        ft_memset(res, 0xaa, size);

    pthread_mutex_unlock(&g_mutex);

    return res;
}