#include "../../includes/malloc.h"

t_zoneMemoireType   get_page_type(size_t size)
{
    if (size <= (size_t)TINY_BLOCK_SIZE)
        return (TINY);
    else if (size <= (size_t)SMALL_BLOCK_SIZE)
        return (SMALL);
    return (LARGE);
}

page_memory_t       *get_last_page(page_memory_t *page)
{
    if (!page)
        return (NULL);
    while(page->next)
        page = page->next;
    return (page);
}

size_t              get_page_size(size_t size)
{
    t_zoneMemoireType group;

    group = get_page_type(size);
    if (group == TINY)
        return ((size_t)TINY_PAGE_SIZE);
    else if (group == SMALL)
        return ((size_t)SMALL_PAGE_SIZE);
    return (size + sizeof(page_memory_t) + sizeof(block_memory_t));
}

page_memory_t       *get_page_free(page_memory_t *start, t_zoneMemoireType type, size_t require_size)
{
    page_memory_t *page;

    page = (page_memory_t *)start;
    while (page)
    {
        if (!(page->type == type)) {
            page = page->next;
            continue;
        }
        if (page->free_len >= require_size)
            return (page);
        page = page->next;
    }
    return (NULL);
}

page_memory_t       *get_page_with_block_size(const size_t size)
{
    page_memory_t       *default_page;
    t_zoneMemoireType   page_type;
    page_memory_t       *page;

    default_page = g_page_memory;
    page_type = get_page_type(size);
    page = get_page_free(default_page, page_type, size + sizeof(block_memory_t));

    if (page == NULL)
    {
        if (!(page = create_page(page_type, size)))
            return (NULL);
        page->next = default_page;
        if (page->next)
            page->next->prev = page;
        g_page_memory = page;
    }
    return (page);
}