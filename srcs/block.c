#include "../includes/malloc.h"

void	remove_block(page_memory_t *heap, block_memory_t *block)
{
	if (block->is_free && !block->next)
	{
		if (block->prev)
			block->prev->next = NULL;
		heap->free_len += block->is_free + sizeof(block_memory_t);
		heap->block_count--;
	}
}
