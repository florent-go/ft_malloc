#include "../../includes/malloc.h"

block_memory_t *merge_block(page_memory_t *page, block_memory_t *block)
{
    if (page && block && block->next && block->next->is_free)
	{
		block->len += block->next->len + sizeof(block_memory_t);
		if (block->next && block->next->next)
			block->next->next->prev = block;
		block->next = block->next->next;
		page->block_count--;
	}
	if (page && block && block->prev && block->prev->is_free)
	{
		block->prev->next = block->next;
		if (block->next)
			block->next->prev = block->prev;
		block->prev->len += block->len + sizeof(block_memory_t);
		page->block_count--;
		return (block->prev);
	}
	return (NULL);
}
