#include "../../includes/malloc.h"

void init_block(block_memory_t *block, size_t size)
{
    block->prev = NULL;
    block->next = NULL;
    block->len = size;
    block->is_free = false;
}