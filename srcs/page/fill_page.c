#include "../../includes/malloc.h"

void *add_empty_block(page_memory_t *page, size_t size)
{
    block_memory_t  *new_block;
    block_memory_t  *last_block;

	new_block = (block_memory_t *)page_shift(page);
	last_block = NULL;
	if (page->block_count)
	{
		last_block = get_last_block(new_block);
		new_block = (block_memory_t *)(block_shift(last_block) + last_block->len);
	}
	init_block(new_block, size);
	if (page->block_count)
	{
		last_block->next = new_block;
		new_block->prev = last_block;
	}
	page->block_count++;
	page->free_len -= (new_block->len + sizeof(block_memory_t));
    return ((void *)block_shift(new_block));
}