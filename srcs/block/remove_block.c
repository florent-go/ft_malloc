#include "../../includes/malloc.h"

void	remove_block(page_memory_t *page, block_memory_t *block)
{
	if (block->is_free && !block->next)
	{
		if (block->prev)
			block->prev->next = NULL;
		page->free_len += block->len + sizeof(block_memory_t);
		page->block_count--;
	}
}
