#include "../../includes/malloc.h"

block_memory_t  *get_last_block(block_memory_t *block)
{
	while (block->next)
		block = block->next;
	return (block);
}

void find_available_block(size_t size, page_memory_t **res_page, block_memory_t **res_block)
{
    page_memory_t *page;
    block_memory_t *block;
    t_zoneMemoireType type;

    page = g_page_memory;
    type = get_page_type(size);

    while (page)
    {
        block = (block_memory_t *)page_shift(page);
        while (page->type == type && block)
        {
            if (block->is_free && (block->len >= size + sizeof(block_memory_t)))
            {
                *res_page = page;
                *res_block = block;
                return ;
            }
            block = block->next;
        }
        page = page->next;
    }
    *res_page = NULL;
    *res_block = NULL;
}

void find_block_of_ptr(void *ptr, page_memory_t **res_page, block_memory_t **res_block, page_memory_t *page)
{
    block_memory_t *block;

    block = NULL;
    while (page)
    {
        block = (block_memory_t *)page_shift(page);
        while (block)
        {
            if (block_shift(block) == ptr)
            {
                *res_page = page;
                *res_block = block;
                return ;
            }
            block = block->next;
        }
        page = page->next;
    }
    *res_page = NULL;
    *res_block = NULL;
}