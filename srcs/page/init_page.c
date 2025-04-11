#include "../../includes/malloc.h"

page_memory_t *create_page(t_zoneMemoireType type, size_t block_size)
{
    size_t          page_size;
    page_memory_t   *page;

    page_size = get_page_size(block_size);
    if (page_size > get_system_limit())
        return (NULL);
    page = (page_memory_t *)mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1,0);
    if (page == MAP_FAILED)
        return (NULL);
    ft_bzero(page, sizeof(page));
    page->type = type;
    page->total_len = page_size;
    page->free_len = page_size - sizeof(page_memory_t);
    return (page);
}
