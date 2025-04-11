#include "../includes/malloc.h"

void    start_free(void *ptr)
{
    page_memory_t   *page;
    block_memory_t  *block;
    block_memory_t  *ret_ptr;

    page = g_page_memory;
    if (!ptr || !page)
        return ;
    find_block_of_ptr(ptr, &page, &block, page);
    if (block && page)
    {
        ret_ptr = merge_block(page, block);
        if (ret_ptr)
            block = ret_ptr;
        else
            block = block;
		remove_block(page, block);
		remove_empty_page(page);
    }
}

void free(void *ptr)
{
    pthread_mutex_lock(&g_mutex);
    start_free(ptr);
    pthread_mutex_unlock(&g_mutex);
}