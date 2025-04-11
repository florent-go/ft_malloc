#include "../../includes/malloc.h"

void			remove_empty_page(page_memory_t *page)
{
	if (page->block_count)
		return ;
	if (page->prev)
		page->prev->next = page->next;
	if (page->next)
		page->next->prev = page->prev;
	if (!is_last_of_preallocated(page))
	{
		if (page == g_page_memory)
			g_page_memory = page->next;
		munmap(page, page->total_len);
	}
}