#include "../../includes/malloc.h"

void        divide_block(block_memory_t *block, size_t size, page_memory_t *page)
{
    block_memory_t *free_block;

    free_block = block_shift(block) + size;
    init_block(free_block, block->next - free_block);
    free_block->is_free= true;
    free_block->prev = block;
    free_block->next = block->next;
    page->block_count++;
    block->next = free_block;
    block->len = size;
    block->is_free = false;
}

block_memory_t *try_fill_block(size_t size)
{
    block_memory_t *block;
    page_memory_t *page;

    find_available_block(size, &page, &block);
    if (!block || !page)
        return NULL;

    divide_block(block, size, page);
    return block;

}